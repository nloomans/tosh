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

#include "history.h"

struct s_history_node		*unpack_history_node(const t_list_conn *conn)
{
	if (conn == NULL)
	{
		return (NULL);
	}
	else
	{
		return ((struct s_history_node *)
			((char *)conn - offsetof(struct s_history_node, conn)));
	}
}
