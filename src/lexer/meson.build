python3 = find_program('python3')

fsm_c = custom_target('fsm_c',
	command: [python3, files('genfsm.py', '../../.header', 'private.h')],
	output: 'fsm.c',
	capture: true,
)

src_files += files(
	'token.c',
	'tokenize.c',
	'handler.c',
	'unpack_token.c',
	'clear.c',
)
src_files += fsm_c

test_files += files(
	'tokenize_test.c',
)
