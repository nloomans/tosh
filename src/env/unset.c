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

void					env_unset(t_env *env, char const *const key)
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
