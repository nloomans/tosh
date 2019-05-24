#include <criterion/criterion.h>
#include "token.h"
#include <string.h>

Test(token_parser, string_literal) {
	t_token token;
	char *stream = "the quick brown fox jumps over the lazy dog";
	size_t stream_length = strlen(stream);

	cr_expect_eq(parse_token(&token, &stream), 0);
	cr_expect_eq(token.type, E_TXT);
	cr_expect_eq(token.s_length, stream_length);
	cr_expect_str_empty(stream);
}
