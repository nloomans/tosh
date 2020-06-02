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

bool	parser__next_if_token(t_parser *const p,
			const enum e_token_type type,
			const char *const string)
{
	if (parser__is_token(p, type, string))
	{
		parser__next_token(p);
		return (true);
	}
	return (false);
}
