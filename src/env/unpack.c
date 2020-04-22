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

struct s_env_pair			*unpack_env(t_list_conn *const node)
{
	if (node == NULL)
	{
		return (NULL);
	}
	else
	{
		return ((struct s_env_pair *)
			((char *)node - offsetof(struct s_env_pair, conn)));
	}
}
