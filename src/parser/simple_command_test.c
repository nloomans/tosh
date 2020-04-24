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
#include "../lexer/lexer.h"
#include "test.h"
#include "private.h"

Test(parse_simple_command, parses_a_simple_command)
{
	t_parser	p;

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
		.string = "foo.txt",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = WORD,
		.string = "ls",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = WORD,
		.string = "-a",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = OPERATOR,
		.string = "<<",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = WORD,
		.string = "EOF",
	}).conn);
	ft_list_insert(&p.all_token, p.all_token.last, &((struct s_token){
		.type = WORD,
		.string = "-l",
	}).conn);

	p.cursor = p.all_token.first;

	struct s_simple_command *simple_command = parse_simple_command(&p);

	cr_assert_str_empty(p.error.msg);
	cr_expect_eq(p.cursor, NULL);
	check_simple_command(simple_command, &(struct s_simple_command){
		.prefix = &(struct s_cmd_prefix){
			.prefix = NULL,
			.redirect = &(struct s_io_redirect){
				.fd = 2,
				.here = NULL,
				.file = &(struct s_io_file){
					.type = REDIRECT_OUT,
					.filename = "foo.txt",
				},
			},
		},
		.name = "ls",
		.suffix = &(struct s_cmd_suffix){
			.word = "-a",
			.redirect = NULL,
			.suffix = &(struct s_cmd_suffix){
				.word = NULL,
				.redirect = &(struct s_io_redirect){
					.fd = -1,
					.here = &(struct s_io_here){
						.here_end = "EOF",
					},
					.file = NULL,
				},
				.suffix = &(struct s_cmd_suffix){
					.word = "-l",
				},
			},
		},
	});
	free_simple_command(simple_command);
}

Test(parse_simple_command, parses_from_string)
{
	t_parser	p;

	ft_memset(&p, '\0', sizeof(p));
	lexer_tokenize(&p.all_token, "2>foo.txt ls -a <<EOF -l");
	p.cursor = p.all_token.first;

	struct s_simple_command *simple_command = parse_simple_command(&p);
	lexer_clear(&p.all_token);

	cr_assert_str_empty(p.error.msg);
	cr_expect_eq(p.cursor, NULL);
	check_simple_command(simple_command, &(struct s_simple_command){
		.prefix = &(struct s_cmd_prefix){
			.prefix = NULL,
			.redirect = &(struct s_io_redirect){
				.fd = 2,
				.here = NULL,
				.file = &(struct s_io_file){
					.type = REDIRECT_OUT,
					.filename = "foo.txt",
				},
			},
		},
		.name = "ls",
		.suffix = &(struct s_cmd_suffix){
			.word = "-a",
			.redirect = NULL,
			.suffix = &(struct s_cmd_suffix){
				.word = NULL,
				.redirect = &(struct s_io_redirect){
					.fd = -1,
					.here = &(struct s_io_here){
						.here_end = "EOF",
					},
					.file = NULL,
				},
				.suffix = &(struct s_cmd_suffix){
					.word = "-l",
				},
			},
		},
	});
	free_simple_command(simple_command);
}

Test(parse_simple_command, handles_heredoc_error)
{
	t_parser	p;

	ft_memset(&p, '\0', sizeof(p));
	lexer_tokenize(&p.all_token, "2>foo.txt ls -a <<");
	p.cursor = p.all_token.first;

	free_simple_command(parse_simple_command(&p));
	lexer_clear(&p.all_token);

	cr_assert_str_eq(p.error.msg, "incomplete heredoc");
}

Test(parse_simple_command, handles_file_error)
{
	t_parser	p;

	ft_memset(&p, '\0', sizeof(p));
	lexer_tokenize(&p.all_token, "2>foo.txt ls -a >");
	p.cursor = p.all_token.first;

	free_simple_command(parse_simple_command(&p));
	lexer_clear(&p.all_token);

	cr_assert_str_eq(p.error.msg, "no filename after redirect");
}
