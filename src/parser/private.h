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

#ifndef PRIVATE_H
# define PRIVATE_H

# include "../error/error.h"
# include "parser.h"

typedef struct			s_parser
{
	t_list_meta			tokens;
	t_list_conn			*cursor;
	t_error				error;
}						t_parser;

void					parser__errorf(t_parser *const p,
							const char *const fmt, ...);
struct s_token			*parser__next_token(t_parser *const p);
struct s_token			*parser__peek_token(const t_parser *const p);
bool					parser__is_token(const t_parser *const p,
							const enum e_token_type type,
							const char *const string);
bool					parser__next_if_token(t_parser *const p,
							const enum e_token_type type,
							const char *const string);

struct s_io_redirect	*parse_io_redirect(t_parser *const p);
void					free_io_redirect(
							struct s_io_redirect *const io_redirect);

struct s_io_file		*parse_io_file(t_parser *const p);
void					free_io_file(struct s_io_file *const io_file);

struct s_io_here		*parse_io_here(t_parser *const p);
void					free_io_here(struct s_io_here *const io_here);

#endif
