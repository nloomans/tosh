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

#ifndef TEST_H
# define TEST_H

# include "private.h"

void		check_string(const char *const a, const char *const b);
void		check_complete_command(
				const struct s_complete_command *const a,
				const struct s_complete_command *const b);
void		check_list(
				const struct s_list *const a,
				const struct s_list *const b);
void		check_pipe_sequence(
				const struct s_pipe_sequence *const a,
				const struct s_pipe_sequence *const b);
void		check_simple_command(
				const struct s_simple_command *const a,
				const struct s_simple_command *const b);
void		check_cmd_prefix(
				const struct s_cmd_prefix *const a,
				const struct s_cmd_prefix *const b);
void		check_cmd_suffix(
				const struct s_cmd_suffix *const a,
				const struct s_cmd_suffix *const b);
void		check_io_redirect(
				const struct s_io_redirect *const a,
				const struct s_io_redirect *const b);
void		check_io_file(
				const struct s_io_file *const a,
				const struct s_io_file *const b);
void		check_io_here(
				const struct s_io_here *const a,
				const struct s_io_here *const b);

#endif
