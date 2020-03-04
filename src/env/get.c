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

char					*env_get(t_env const *const env, char const *const key)
{
	struct s_env_pair	*temp;
	t_list_conn			*iter;

	iter = env->list.first;
	while (iter)
	{
		temp = unpack_env(iter);
		if (ft_strequ(temp->key, key) == 1)
		{
			return (temp->value);
		}
		iter = iter->next;
	}
	return (NULL);
}
