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

#include "env.h"

void					env_unset(t_env *env, char const *const key)
{
	struct s_env_list	*del_holder;
	struct s_env_list	*temp;
	t_list_conn			**iter;

	iter = &env->meta.first;
	while (*iter)
	{
		temp = unpack_env(*iter);
		if (ft_strequ(temp->key, key) == 1)
		{
			del_holder = temp;
			ft_list_unlink(&env->meta, &temp->conn);
			ft_strdel(&del_holder->key);
			ft_strdel(&del_holder->value);
			ft_bzero(del_holder, sizeof(struct s_env_list));
			free(del_holder);
			break ;
		}
		else
			iter = &((*iter)->next);
	}
}
