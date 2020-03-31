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
