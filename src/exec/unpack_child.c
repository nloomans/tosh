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
