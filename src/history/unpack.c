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

struct s_history__line		*unpack_line(const t_list_conn *conn)
{
	if (conn == NULL)
	{
		return (NULL);
	}
	else
	{
		return ((struct s_history__line *)
			((char *)conn - offsetof(struct s_history__line, conn)));
	}
}
