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

#include <stddef.h>

#include "lexer.h"

struct s_token	*unpack_token(t_list_conn *const node)
{
	if (node == NULL)
	{
		return (NULL);
	}
	else
	{
		return ((struct s_token *)
			((char *)node - offsetof(struct s_token, conn)));
	}
}
