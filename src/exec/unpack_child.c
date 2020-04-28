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

#include "private.h"

struct s_child	*unpack_child(const struct s_list_conn *const node)
{
	if (node == NULL)
	{
		return (NULL);
	}
	else
	{
		return ((struct s_child *)
			((char *)node - offsetof(struct s_child, conn)));
	}
}
