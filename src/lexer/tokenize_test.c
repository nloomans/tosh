/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: aholster <aholster@student.codam.nl>          +:+                    */
/*       ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*       nloomans <nloomans@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "lexer.h"

#define TOKEN_TESTER(input, expected_all_token) do							\
{																			\
	t_list_meta		all_token;												\
	struct s_token	*token;													\
	size_t			expected_all_token_len =								\
		sizeof(expected_all_token) / sizeof(expected_all_token[0]);			\
																			\
	lexer_tokenize(&all_token, input);										\
	cr_expect_eq(all_token.len, expected_all_token_len,						\
		"Unexpected amount of tokens: expected %zu, got %zu",				\
			expected_all_token_len, all_token.len);							\
																			\
	token = unpack_token(all_token.first);									\
	for (size_t i = 0; i < expected_all_token_len; i++)						\
	{																		\
		cr_expect_eq(token->type, expected_all_token[i].type,				\
			"Unexpected type for token %zu: expected %s, got %s",			\
				i, g_token_type_names[expected_all_token[i].type],			\
				g_token_type_names[token->type]);							\
		cr_expect_str_eq(token->string, expected_all_token[i].string,		\
			"Unexpected string for token %zu: expected '%s', got '%s'",		\
				i, expected_all_token[i].string, token->string);			\
		token = unpack_token(token->conn.next);								\
	}																		\
} while (0);

Test(lexer_tokenize, basic_words) {
	TOKEN_TESTER("hello world", ((struct s_token[]){
		{ .type = WORD, .string = "hello" },
		{ .type = WORD, .string = "world" },
	}));
}

Test(lexer_tokenize, redirect) {
	TOKEN_TESTER("cat foo.txt 2 >/dev/null", ((struct s_token[]){
		{ .type = WORD, .string = "cat" },
		{ .type = WORD, .string = "foo.txt" },
		{ .type = WORD, .string = "2" },
		{ .type = OP_REDIR, .string = ">" },
		{ .type = WORD, .string = "/dev/null" },
	}));
	TOKEN_TESTER("cat foo.txt 2 > /dev/null", ((struct s_token[]){
		{ .type = WORD, .string = "cat" },
		{ .type = WORD, .string = "foo.txt" },
		{ .type = WORD, .string = "2" },
		{ .type = OP_REDIR, .string = ">" },
		{ .type = WORD, .string = "/dev/null" },
	}));
	TOKEN_TESTER(">/dev/null cat foo.txt", ((struct s_token[]){
		{ .type = OP_REDIR, .string = ">" },
		{ .type = WORD, .string = "/dev/null" },
		{ .type = WORD, .string = "cat" },
		{ .type = WORD, .string = "foo.txt" },
	}));
	TOKEN_TESTER("> /dev/null cat foo.txt", ((struct s_token[]){
		{ .type = OP_REDIR, .string = ">" },
		{ .type = WORD, .string = "/dev/null" },
		{ .type = WORD, .string = "cat" },
		{ .type = WORD, .string = "foo.txt" },
	}));
	TOKEN_TESTER("2 > /dev/null cat foo.txt", ((struct s_token[]){
		{ .type = WORD, .string = "2" },
		{ .type = OP_REDIR, .string = ">" },
		{ .type = WORD, .string = "/dev/null" },
		{ .type = WORD, .string = "cat" },
		{ .type = WORD, .string = "foo.txt" },
	}));
}

Test(lexer_tokenize, redirect_io_number) {
	TOKEN_TESTER("cat foo.txt 2>/dev/null", ((struct s_token[]){
		{ .type = WORD, .string = "cat" },
		{ .type = WORD, .string = "foo.txt" },
		{ .type = IO_NUMBER, .string = "2" },
		{ .type = OP_REDIR, .string = ">" },
		{ .type = WORD, .string = "/dev/null" },
	}));
	TOKEN_TESTER("cat foo.txt 2> /dev/null", ((struct s_token[]){
		{ .type = WORD, .string = "cat" },
		{ .type = WORD, .string = "foo.txt" },
		{ .type = IO_NUMBER, .string = "2" },
		{ .type = OP_REDIR, .string = ">" },
		{ .type = WORD, .string = "/dev/null" },
	}));
	TOKEN_TESTER("cat foo.txt 2>3", ((struct s_token[]){
		{ .type = WORD, .string = "cat" },
		{ .type = WORD, .string = "foo.txt" },
		{ .type = IO_NUMBER, .string = "2" },
		{ .type = OP_REDIR, .string = ">" },
		{ .type = WORD, .string = "3" },
	}));
	TOKEN_TESTER("cat foo.txt 2> 3", ((struct s_token[]){
		{ .type = WORD, .string = "cat" },
		{ .type = WORD, .string = "foo.txt" },
		{ .type = IO_NUMBER, .string = "2" },
		{ .type = OP_REDIR, .string = ">" },
		{ .type = WORD, .string = "3" },
	}));
	TOKEN_TESTER("2>3 cat foo.txt", ((struct s_token[]){
		{ .type = IO_NUMBER, .string = "2" },
		{ .type = OP_REDIR, .string = ">" },
		{ .type = WORD, .string = "3" },
		{ .type = WORD, .string = "cat" },
		{ .type = WORD, .string = "foo.txt" },
	}));
	TOKEN_TESTER("2> 3 cat foo.txt", ((struct s_token[]){
		{ .type = IO_NUMBER, .string = "2" },
		{ .type = OP_REDIR, .string = ">" },
		{ .type = WORD, .string = "3" },
		{ .type = WORD, .string = "cat" },
		{ .type = WORD, .string = "foo.txt" },
	}));
}

Test(lexer_tokenize, blank) {
	char *all_input[] = {
		"hello world",
		"hello\tworld",
		"\thello\tworld\t",
		" hello world ",
		" \t hello \t world \t ",
		"\t \thello\t \tworld\t \t",
	};

	for (size_t i = 0; i < sizeof(all_input) / sizeof(all_input[0]); i++)
	{
		TOKEN_TESTER(all_input[i], ((struct s_token[]){
			{ .type = WORD, .string = "hello" },
			{ .type = WORD, .string = "world" },
		}));
	}
}

Test(lexer_tokenize, empty) {
	t_list_meta all_token;

	lexer_tokenize(&all_token, "");
	cr_expect_eq(all_token.len, 0);

	lexer_tokenize(&all_token, " ");
	cr_expect_eq(all_token.len, 0);

	lexer_tokenize(&all_token, "\t");
	cr_expect_eq(all_token.len, 0);

	lexer_tokenize(&all_token, "\t \t");
	cr_expect_eq(all_token.len, 0);

	lexer_tokenize(&all_token, " \t ");
	cr_expect_eq(all_token.len, 0);
}
