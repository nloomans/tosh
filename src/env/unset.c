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

void					env_unset(t_env *const env, const char *const key)
{
	struct s_env_pair	*del_holder;
	struct s_env_pair	*temp;
	t_list_conn			**iter;

	iter = &env->list.first;
	while (*iter)
	{
		temp = unpack_env(*iter);
		if (ft_strequ(temp->key, key) == 1)
		{
			del_holder = temp;
			ft_list_unlink(&env->list, &temp->conn);
			ft_strdel(&del_holder->key);
			ft_strdel(&del_holder->value);
			ft_memdel((void **)&del_holder);
			break ;
		}
		else
			iter = &((*iter)->next);
	}
}
