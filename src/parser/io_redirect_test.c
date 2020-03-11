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
#include "private.h"

Test(parse_io_redirect, parses_simple_redirect)
{
	t_parser p;

	ft_memset(&p, '\0', sizeof(p));
	ft_list_insert(&p.tokens, p.tokens.last, &((struct s_token){
		.type = OPERATOR,
		.string = ">",
	}).conn);
	ft_list_insert(&p.tokens, p.tokens.last, &((struct s_token){
		.type = WORD,
		.string = "text.txt",
	}).conn);

	p.cursor = p.tokens.first;

	struct s_io_redirect *io_redirect = parse_io_redirect(&p);

	cr_assert_str_empty(p.error.msg);
	cr_assert_not_null(io_redirect);
	cr_assert_eq(io_redirect->fd, 1);
	cr_assert_eq(io_redirect->type, REDIRECT_OUT);
	cr_assert_str_eq(io_redirect->file, "text.txt");
	cr_assert_eq(p.cursor, NULL);
}

Test(parse_io_redirect, parses_with_io_number)
{
	t_parser p;

	ft_memset(&p, '\0', sizeof(p));
	ft_list_insert(&p.tokens, p.tokens.last, &((struct s_token){
		.type = IO_NUMBER,
		.string = "2",
	}).conn);
	ft_list_insert(&p.tokens, p.tokens.last, &((struct s_token){
		.type = OPERATOR,
		.string = ">",
	}).conn);
	ft_list_insert(&p.tokens, p.tokens.last, &((struct s_token){
		.type = WORD,
		.string = "text.txt",
	}).conn);

	p.cursor = p.tokens.first;

	struct s_io_redirect *io_redirect = parse_io_redirect(&p);

	cr_assert_str_empty(p.error.msg);
	cr_assert_not_null(io_redirect);
	cr_assert_eq(io_redirect->fd, 2);
	cr_assert_eq(io_redirect->type, REDIRECT_OUT);
	cr_assert_str_eq(io_redirect->file, "text.txt");
	cr_assert_eq(p.cursor, NULL);
}

Test(parse_io_redirect, errors_incomplete)
{
	t_parser p;

	ft_memset(&p, '\0', sizeof(p));
	ft_list_insert(&p.tokens, p.tokens.last, &((struct s_token){
		.type = OPERATOR,
		.string = ">",
	}).conn);

	p.cursor = p.tokens.first;

	struct s_io_redirect *io_redirect = parse_io_redirect(&p);

	cr_assert_str_eq(p.error.msg, "no filename after redirect");
	cr_assert_null(io_redirect);
	cr_assert_eq(p.cursor, NULL);
}

Test(parse_io_redirect, ignores_non_redirects)
{
	t_parser p;

	ft_memset(&p, '\0', sizeof(p));
	ft_list_insert(&p.tokens, p.tokens.last, &((struct s_token){
		.type = WORD,
		.string = "cat",
	}).conn);
	ft_list_insert(&p.tokens, p.tokens.last, &((struct s_token){
		.type = WORD,
		.string = "text.txt",
	}).conn);

	p.cursor = p.tokens.first;

	struct s_io_redirect *io_redirect = parse_io_redirect(&p);

	cr_assert_str_empty(p.error.msg);
	cr_assert_null(io_redirect);
	cr_assert_eq(p.cursor, p.tokens.first);
}