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

#include <stddef.h>

#include "lexer.h"

struct s_token	*unpack_token(t_list_conn *node)
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
