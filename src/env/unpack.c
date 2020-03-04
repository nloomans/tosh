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
#include "env.h"

struct s_env_list			*unpack_env(t_list_conn *const node)
{
	if (node == NULL)
	{
		return (NULL);
	}
	else
	{
		return ((struct s_env_list *)\
			((char *)node - offsetof(struct s_env_list, conn)));
	}
}
