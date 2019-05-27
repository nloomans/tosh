#include <criterion/criterion.h>
#include "token.h"
#include <string.h>

Test(token_parser, string_literal) {
	t_token token;
	char *stream = "the quick brown fox jumps over the lazy dog";
	size_t stream_length = strlen(stream);

	cr_expect_eq(parse_token(&token, &stream), 0);

	cr_expect_eq(token.type, E_TXT);
	cr_expect_eq(token.flags, 0);
	cr_expect_eq(token.width, 0);
	cr_expect_eq(token.s_length, stream_length);
	cr_expect_str_empty(stream);
}

Test(token_parser, simple_number) {
	t_token token;
	char *stream = "%dignore me";

	cr_expect_eq(parse_token(&token, &stream), 1);

	cr_expect_eq(token.type, E_INT);
	cr_expect_eq(token.flags, 0);
	cr_expect_eq(token.width, 0);
	cr_expect_eq(token.size, E_N);
}

Test(token_parser, dyn_width_precition_number) {
	t_token token;
	char *stream = "%*.*dignore me";

	cr_expect_eq(parse_token(&token, &stream), 1);

	cr_expect_eq(token.type, E_INT);
	cr_expect_eq(token.flags, FLAGS_PRECISION);
	cr_expect_eq(token.width, DEFERRED_WILDCARD);
	cr_expect_eq(token.size, E_N);
	cr_expect_eq(token.precision, DEFERRED_WILDCARD);
}
