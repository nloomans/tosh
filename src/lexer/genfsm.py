import sys
import shutil
from enum import Enum, auto

if len(sys.argv) != 3:
	print("Usage: {} <header template> <include header>")
	exit(1)

header_file_name = sys.argv[1]
include_header_file_name = sys.argv[2]

class State(Enum):
	EOF = 'eof'
	BLANK = 'blank'
	WORD = 'word'
	IO_NUMBER = 'io_number'
	REDIR_LEFT = 'redir_left'
	REDIR_RIGHT = 'redir_right'
	OPERATOR_EXIT = 'operator_exit'
	QUOTE_SINGLE = 'quote_single'
	QUOTE_SLASH = 'quote_slash'
	QUOTE_DOUBLE = 'quote_double'
	QUOTE_DOUBLE_SLASH = 'quote_double_slash'
	COMMENT = 'comment'

class Token(Enum):
	WORD = 'WORD'
	IO_NUMBER = 'IO_NUMBER'
	OPERATOR = 'OPERATOR'

class Input(Enum):
	NULL = auto()
	BLANK = auto()
	DIGIT = auto()
	SINGLE_QUOTE = auto()
	DOUBLE_QUOTE = auto()
	BACKSLASH = auto()
	LEFT_ARROW = auto()
	RIGHT_ARROW = auto()
	NEWLINE = auto()
	OP_CONTROL = auto()
	AMPERSAND = auto()
	POUNDSIGN = auto()

input_map = {
	Input.NULL: ['\\0'],
	Input.BLANK: [' ', '\\t'],
	Input.DIGIT: ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'],
	Input.SINGLE_QUOTE: ['\\\''],
	Input.DOUBLE_QUOTE: ['"'],
	Input.BACKSLASH: ['\\\\'],
	Input.LEFT_ARROW: ['<'],
	Input.RIGHT_ARROW: ['>'],
	Input.NEWLINE: ['\\n'],
	Input.OP_CONTROL: ['\\n', ';', '|'],
	Input.AMPERSAND: ['&'],
	Input.POUNDSIGN: ['#'],
}

def fsm(all_rules):
	output = '#include "{}"\n'.format(include_header_file_name)
	output += "\n"
	output += "const struct s_fsm_state\t\tg_machine_table[] = {\n"
	output += "".join(all_rules)
	output += "};\n"
	return output

def rules(from_state, rules, catch_rule):
	output = ""
	output += "\t[{}] = {{\n".format(from_state.value)
	output += "\t\t.rules = {\n"
	for key, rule in rules.items():
		for char in input_map[key]:
			output += "\t\t\t['{}'] = {},\n".format(char, rule)
	output += "\t\t},\n"
	output += "\t\t.catch_rule = {},\n".format(catch_rule)
	output += "\t},\n"
	return output

def rule(to_state, delimit=None, add_char=False):
	return "{{ {}, {}, {} }}".format(
		to_state.value,
		delimit.value if delimit != None else "UNDETERMINED",
		"true" if add_char else "false",
	)

output = fsm([
	rules(State.BLANK, {

		Input.NULL:			rule(State.EOF),
		Input.BLANK:		rule(State.BLANK),
		Input.POUNDSIGN:	rule(State.COMMENT),
		Input.OP_CONTROL:	rule(State.OPERATOR_EXIT,							add_char=True),

		Input.DIGIT:		rule(State.IO_NUMBER,								add_char=True),

		Input.LEFT_ARROW:	rule(State.REDIR_LEFT,								add_char=True),
		Input.RIGHT_ARROW:	rule(State.REDIR_RIGHT,								add_char=True),

		Input.SINGLE_QUOTE: rule(State.QUOTE_SINGLE,							add_char=True),
		Input.DOUBLE_QUOTE: rule(State.QUOTE_DOUBLE,							add_char=True),
		Input.BACKSLASH:	rule(State.QUOTE_SLASH,								add_char=True),

	}, catch_rule=rule(State.WORD, add_char=True)),

	rules(State.WORD, {

		Input.NULL:			rule(State.EOF,				delimit=Token.WORD),
		Input.BLANK:		rule(State.BLANK,			delimit=Token.WORD),
		Input.POUNDSIGN:	rule(State.COMMENT,			delimit=Token.WORD),
		Input.OP_CONTROL:	rule(State.OPERATOR_EXIT,	delimit=Token.WORD,		add_char=True),

		Input.LEFT_ARROW:	rule(State.REDIR_LEFT,		delimit=Token.WORD,		add_char=True),
		Input.RIGHT_ARROW:	rule(State.REDIR_RIGHT,		delimit=Token.WORD,		add_char=True),

		Input.SINGLE_QUOTE: rule(State.QUOTE_SINGLE,							add_char=True),
		Input.DOUBLE_QUOTE: rule(State.QUOTE_DOUBLE,							add_char=True),
		Input.BACKSLASH:	rule(State.QUOTE_SLASH,								add_char=True),

	}, catch_rule=rule(State.WORD, add_char=True)),

	rules(State.IO_NUMBER, {

		Input.NULL:			rule(State.EOF,				delimit=Token.WORD),
		Input.BLANK:		rule(State.BLANK, 			delimit=Token.WORD),
		Input.POUNDSIGN:	rule(State.COMMENT,			delimit=Token.WORD),
		Input.OP_CONTROL:	rule(State.OPERATOR_EXIT,	delimit=Token.WORD,		add_char=True),

		Input.DIGIT:		rule(State.IO_NUMBER,								add_char=True),

		Input.LEFT_ARROW:	rule(State.REDIR_LEFT,		delimit=Token.IO_NUMBER,add_char=True),
		Input.RIGHT_ARROW:	rule(State.REDIR_RIGHT, 	delimit=Token.IO_NUMBER,add_char=True),

		Input.SINGLE_QUOTE: rule(State.QUOTE_SINGLE,							add_char=True),
		Input.DOUBLE_QUOTE: rule(State.QUOTE_DOUBLE,							add_char=True),
		Input.BACKSLASH:	rule(State.QUOTE_SLASH,								add_char=True),

	}, catch_rule=rule(State.WORD, add_char=True)),

	rules(State.REDIR_LEFT, {

		Input.NULL:			rule(State.EOF,				delimit=Token.OPERATOR),
		Input.BLANK:		rule(State.BLANK,			delimit=Token.OPERATOR),
		Input.POUNDSIGN:	rule(State.COMMENT,			delimit=Token.OPERATOR),
		Input.OP_CONTROL:	rule(State.OPERATOR_EXIT,	delimit=Token.OPERATOR,	add_char=True),

		Input.SINGLE_QUOTE:	rule(State.QUOTE_SINGLE,	delimit=Token.OPERATOR,	add_char=True),
		Input.DOUBLE_QUOTE:	rule(State.QUOTE_DOUBLE,	delimit=Token.OPERATOR,	add_char=True),
		Input.BACKSLASH:	rule(State.QUOTE_SLASH,		delimit=Token.OPERATOR,	add_char=True),

		Input.LEFT_ARROW:	rule(State.OPERATOR_EXIT,							add_char=True),
		Input.AMPERSAND:	rule(State.OPERATOR_EXIT,							add_char=True),

	}, catch_rule=rule(State.WORD, delimit=Token.OPERATOR, add_char=True)),

	rules(State.REDIR_RIGHT, {

		Input.NULL:			rule(State.EOF,				delimit=Token.OPERATOR),
		Input.BLANK:		rule(State.BLANK,			delimit=Token.OPERATOR),
		Input.POUNDSIGN:	rule(State.COMMENT,			delimit=Token.OPERATOR),
		Input.OP_CONTROL:	rule(State.OPERATOR_EXIT,	delimit=Token.OPERATOR,	add_char=True),

		Input.SINGLE_QUOTE:	rule(State.QUOTE_SINGLE,	delimit=Token.OPERATOR,	add_char=True),
		Input.DOUBLE_QUOTE:	rule(State.QUOTE_DOUBLE,	delimit=Token.OPERATOR,	add_char=True),
		Input.BACKSLASH:	rule(State.QUOTE_SLASH,		delimit=Token.OPERATOR,	add_char=True),

		Input.RIGHT_ARROW:	rule(State.OPERATOR_EXIT,							add_char=True),
		Input.AMPERSAND:	rule(State.OPERATOR_EXIT,							add_char=True),

	}, catch_rule=rule(State.WORD, delimit=Token.OPERATOR, add_char=True)),

	rules(State.OPERATOR_EXIT, {

		Input.NULL:			rule(State.EOF,				delimit=Token.OPERATOR),
		Input.BLANK:		rule(State.BLANK,			delimit=Token.OPERATOR),
		Input.POUNDSIGN:	rule(State.COMMENT,			delimit=Token.OPERATOR),
		Input.OP_CONTROL:	rule(State.OPERATOR_EXIT,	delimit=Token.OPERATOR, add_char=True),

		Input.DIGIT:		rule(State.IO_NUMBER,		delimit=Token.OPERATOR,	add_char=True),

		Input.SINGLE_QUOTE:	rule(State.QUOTE_SINGLE,	delimit=Token.OPERATOR,	add_char=True),
		Input.DOUBLE_QUOTE:	rule(State.QUOTE_DOUBLE,	delimit=Token.OPERATOR,	add_char=True),
		Input.BACKSLASH:	rule(State.QUOTE_SLASH,		delimit=Token.OPERATOR,	add_char=True),

		Input.LEFT_ARROW:	rule(State.REDIR_LEFT,		delimit=Token.OPERATOR, add_char=True),
		Input.RIGHT_ARROW:	rule(State.REDIR_RIGHT,		delimit=Token.OPERATOR, add_char=True),

	}, catch_rule=rule(State.WORD, delimit=Token.OPERATOR, add_char=True)),

	rules(State.QUOTE_SINGLE, {

		Input.NULL:			rule(State.EOF,				delimit=Token.WORD),
		Input.SINGLE_QUOTE: rule(State.WORD,									add_char=True),

	}, catch_rule=rule(State.QUOTE_SINGLE, add_char=True)),

	rules(State.QUOTE_SLASH, {

		Input.NULL:			rule(State.EOF, 			delimit=Token.WORD),

	}, catch_rule=rule(State.WORD, add_char=True)),

	rules(State.QUOTE_DOUBLE, {

		Input.NULL:			rule(State.EOF,				delimit=Token.WORD),
		Input.DOUBLE_QUOTE: rule(State.WORD,									add_char=True),
		Input.BACKSLASH:	rule(State.QUOTE_DOUBLE_SLASH,						add_char=True),

	}, catch_rule=rule(State.QUOTE_DOUBLE, add_char=True)),

	rules(State.QUOTE_DOUBLE_SLASH, {

		Input.NULL:			rule(State.EOF,				delimit=Token.WORD),

	}, catch_rule=rule(State.QUOTE_DOUBLE, add_char=True)),

	rules(State.COMMENT, {

		Input.NULL:			rule(State.EOF),
		Input.NEWLINE:		rule(State.OPERATOR_EXIT,							add_char=True),

	}, catch_rule=rule(State.COMMENT)),
])

with open(header_file_name, 'r') as header_file:
	header = header_file.read()
print(header)
print(output, end='')
