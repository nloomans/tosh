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

void					env_unset(t_env *env, char *key)
{
	struct s_env_list	**iter;
	struct s_env_list	*del_holder;

	iter = &(env->list);
	while (*iter)
	{
		if (ft_strequ((*iter)->key, key) == 1)
		{
			del_holder = *iter;
			*iter = (*iter)->next;
			ft_strdel(&del_holder->key);
			ft_strdel(&del_holder->value);
			ft_bzero(del_holder, sizeof(struct s_env_list));
			free(del_holder);
			break ;
		}
		else
		{
			iter = &((*iter)->next);
		}
	}
}
