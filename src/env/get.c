/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tosh - 21 Shell                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

char					*env_get(t_env const *const env, char const *const key)
{
	const struct s_env_pair		*temp;
	t_list_conn					*iter;

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
