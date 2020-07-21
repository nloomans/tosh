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

#ifndef LEXER_H
# define LEXER_H

# include <libft.h>

# include "../error/error.h"

/*
** CAUSION: Update the array in token.c when updating the enum below.
*/

enum						e_token_type
{
	UNDETERMINED,
	WORD,
	IO_NUMBER,
	OPERATOR,
};

extern const char *const	g_token_type_names[5];

# define INITIAL_BUFF 64

struct						s_token
{
	enum e_token_type	type;
	char				*string;
	t_list_conn			conn;
};

struct						s_string
{
	size_t					capacity;
	size_t					len;
	char					*buffer;
};

struct s_token				*unpack_token(t_list_conn *const node);
t_error						lexer_handler(
								t_list_meta *const all_token,
								char **const memory_tape);
void						lexer_clear(t_list_meta *const all_token);

#endif
