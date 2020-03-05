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

void					env_list_delete(t_env *env)
{
	t_list_conn			*current;
	struct s_env_pair	*temp;

	while (env->list.first)
	{
		current = env->list.first;
		ft_list_unlink(&env->list, current);
		temp = unpack_env(current);
		ft_strdel(&temp->key);
		ft_strdel(&temp->value);
		ft_memdel((void **)&temp);
	}
}
