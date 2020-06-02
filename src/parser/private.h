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

#ifndef PRIVATE_H
# define PRIVATE_H

# include "../error/error.h"
# include "parser.h"

typedef struct				s_parser
{
	t_list_meta				all_token;
	t_list_conn				*cursor;
	bool					extra_input_requested;
	t_error					error;
}							t_parser;

void						parser__request_extra_input(t_parser *const p);
void						parser__errorf(t_parser *const p,
								const char *const fmt, ...);
struct s_token				*parser__next_token(t_parser *const p);
struct s_token				*parser__peek_token(const t_parser *const p);
bool						parser__is_token(const t_parser *const p,
								const enum e_token_type type,
								const char *const string);
bool						parser__next_if_token(t_parser *const p,
								const enum e_token_type type,
								const char *const string);

struct s_complete_command	*parse_complete_command(t_parser *const p);
void						free_complete_command(struct s_complete_command
								*const complete_command);

struct s_list				*parse_list(t_parser *const p);
void						free_list(struct s_list *const list);

struct s_pipe_sequence		*parse_pipe_sequence(t_parser *const p);
void						free_pipe_sequence(
								struct s_pipe_sequence *const pipe_sequence);

struct s_simple_command		*parse_simple_command(t_parser *const p);
void						free_simple_command(
								struct s_simple_command *const simple_command);

struct s_cmd_prefix			*parse_cmd_prefix(t_parser *const p);
void						free_cmd_prefix(
								struct s_cmd_prefix *const cmd_prefix);

struct s_cmd_suffix			*parse_cmd_suffix(t_parser *const p);
void						free_cmd_suffix(
								struct s_cmd_suffix *const cmd_suffix);

struct s_io_redirect		*parse_io_redirect(t_parser *const p);
void						free_io_redirect(
								struct s_io_redirect *const io_redirect);

struct s_io_file			*parse_io_file(t_parser *const p);
void						free_io_file(struct s_io_file *const io_file);

struct s_io_here			*parse_io_here(t_parser *const p);
void						free_io_here(struct s_io_here *const io_here);

#endif
