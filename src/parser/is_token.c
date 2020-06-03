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

#include "private.h"

bool	parser__is_token(const t_parser *const p,
			const enum e_token_type type,
			const char *const string)
{
	struct s_token	*token;

	token = unpack_token(p->cursor);
	if (token == NULL)
		return (false);
	if (token->type != type)
		return (false);
	if (string != NULL && ft_strcmp(token->string, string) != 0)
		return (false);
	return (true);
}
