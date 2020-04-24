/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tosh-21Shell                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "test.h"
#include "private.h"

Test(parse_io_redirect, parses_simple_redirect)
{
	t_parser p;

	ft_memset(&p, '\0', sizeof(p));
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = OPERATOR,
		.string = ">",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = WORD,
		.string = "text.txt",
	}).conn);

	p.cursor = p.all_token.first;

	struct s_io_redirect *io_redirect = parse_io_redirect(&p);

	cr_assert_str_empty(p.error.msg);
	cr_assert_eq(p.cursor, NULL);
	check_io_redirect(io_redirect, &(struct s_io_redirect){
		.fd = -1,
		.here = NULL,
		.file = &(struct s_io_file){
			.type = REDIRECT_OUT,
			.filename = "text.txt",
		},
	});
}

Test(parse_io_redirect, parses_with_io_number)
{
	t_parser p;

	ft_memset(&p, '\0', sizeof(p));
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = IO_NUMBER,
		.string = "2",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = OPERATOR,
		.string = ">",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = WORD,
		.string = "text.txt",
	}).conn);

	p.cursor = p.all_token.first;

	struct s_io_redirect *io_redirect = parse_io_redirect(&p);

	cr_assert_str_empty(p.error.msg);
	cr_assert_eq(p.cursor, NULL);
	check_io_redirect(io_redirect, &(struct s_io_redirect){
		.fd = 2,
		.here = NULL,
		.file = &(struct s_io_file){
			.type = REDIRECT_OUT,
			.filename = "text.txt",
		},
	});
}

Test(parse_io_redirect, errors_incomplete)
{
	t_parser p;

	ft_memset(&p, '\0', sizeof(p));
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = OPERATOR,
		.string = ">",
	}).conn);

	p.cursor = p.all_token.first;

	struct s_io_redirect *io_redirect = parse_io_redirect(&p);

	cr_assert_str_eq(p.error.msg, "no filename after redirect");
	cr_assert_null(io_redirect);
	cr_assert_eq(p.cursor, NULL);
}

Test(parse_io_redirect, ignores_non_redirects)
{
	t_parser p;

	ft_memset(&p, '\0', sizeof(p));
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = WORD,
		.string = "cat",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = WORD,
		.string = "text.txt",
	}).conn);

	p.cursor = p.all_token.first;

	struct s_io_redirect *io_redirect = parse_io_redirect(&p);

	cr_assert_str_empty(p.error.msg);
	cr_assert_null(io_redirect);
	cr_assert_eq(p.cursor, p.all_token.first);
}

Test(parse_io_redirect, heredoc)
{
	t_parser p;

	ft_memset(&p, '\0', sizeof(p));
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = OPERATOR,
		.string = "<<",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = WORD,
		.string = "EOF",
	}).conn);

	p.cursor = p.all_token.first;

	struct s_io_redirect *io_redirect = parse_io_redirect(&p);

	cr_assert_str_empty(p.error.msg);
	cr_assert_eq(p.cursor, NULL);
	check_io_redirect(io_redirect, &(struct s_io_redirect){
		.fd = -1,
		.here = &(struct s_io_here){
			.here_end = "EOF",
		},
		.file = NULL,
	});
}

Test(parse_io_redirect, filename_and_heredoc)
{
	t_parser p;

	ft_memset(&p, '\0', sizeof(p));
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = OPERATOR,
		.string = ">",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = WORD,
		.string = "foo.txt",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = OPERATOR,
		.string = "<<",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = WORD,
		.string = "EOF",
	}).conn);

	p.cursor = p.all_token.first;

	struct s_io_redirect *io_redirect = parse_io_redirect(&p);

	cr_assert_str_empty(p.error.msg);
	cr_assert_eq(p.cursor, p.all_token.first->next->next);
	check_io_redirect(io_redirect, &(struct s_io_redirect){
		.fd = -1,
		.here = NULL,
		.file = &(struct s_io_file){
			.type = REDIRECT_OUT,
			.filename = "foo.txt",
		},
	});
}
