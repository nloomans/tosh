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
#include "../lexer/lexer.h"
#include "test.h"
#include "private.h"

Test(parser_parse, parses)
{
	t_list_meta					all_token;
	t_error						error;
	bool						extra_input_requested;
	struct s_complete_command	*complete_command;

	lexer_tokenize(&all_token, "mkdir test ; cd test ; ls -a ; ls | cat | wc -c > fifi ; cat fifi");

	error = parser_parse(&complete_command, &extra_input_requested, &all_token);
	cr_assert_not(is_error(error));
	cr_assert_not(extra_input_requested);

	check_complete_command(complete_command, &(struct s_complete_command){
		.list = &(struct s_list){
			.pipe_sequence = &(struct s_pipe_sequence){
				.simple_command = &(struct s_simple_command){
					.prefix = NULL,
					.name = "mkdir",
					.suffix = &(struct s_cmd_suffix){
						.word = "test",
						.redirect = NULL,
						.suffix = NULL,
					},
				},
			},
			.list = &(struct s_list){
				.pipe_sequence = &(struct s_pipe_sequence){
					.simple_command = &(struct s_simple_command){
						.prefix = NULL,
						.name = "cd",
						.suffix = &(struct s_cmd_suffix){
							.word = "test",
							.redirect = NULL,
							.suffix = NULL,
						},
					},
				},
				.list = &(struct s_list){
					.pipe_sequence = &(struct s_pipe_sequence){
						.simple_command = &(struct s_simple_command){
							.prefix = NULL,
							.name = "ls",
							.suffix = &(struct s_cmd_suffix){
								.word = "-a",
								.redirect = NULL,
								.suffix = NULL,
							},
						},
					},
					.list = &(struct s_list){
						.pipe_sequence = &(struct s_pipe_sequence){
							.simple_command = &(struct s_simple_command){
								.prefix = NULL,
								.name = "ls",
								.suffix = NULL,
							},
							.pipe_sequence = &(struct s_pipe_sequence){
								.simple_command = &(struct s_simple_command){
									.prefix = NULL,
									.name = "cat",
									.suffix = NULL,
								},
								.pipe_sequence = &(struct s_pipe_sequence){
									.simple_command = &(struct s_simple_command){
										.prefix = NULL,
										.name = "wc",
										.suffix = &(struct s_cmd_suffix){
											.word = "-c",
											.redirect = NULL,
											.suffix = &(struct s_cmd_suffix){
												.word = NULL,
												.redirect = &(struct s_io_redirect){
													.fd = -1,
													.here = NULL,
													.file = &(struct s_io_file){
														.type = REDIRECT_OUT,
														.filename = "fifi",
													},
												},
											},
										},
									},
								},
							},
						},
						.list = &(struct s_list){
							.pipe_sequence = &(struct s_pipe_sequence){
								.simple_command = &(struct s_simple_command){
									.prefix = NULL,
									.name = "cat",
									.suffix = &(struct s_cmd_suffix){
										.word = "fifi",
										.redirect = NULL,
									},
								},
							},
						},
					},
				},
			},
		},
	});
}
