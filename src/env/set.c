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

#include <assert.h>
#include "private.h"

int						env_set(t_env *const env,
							char const *const key,
							char const *const value)
{
	struct s_env_pair	*new;

	env_unset(env, key);
	new = ft_memalloc(sizeof(*new));
	if (new == NULL)
		return (-1);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	if (new->key == NULL || new->value == NULL)
	{
		ft_strdel(&new->key);
		ft_strdel(&new->value);
		ft_memdel((void **)&new);
		return (-1);
	}
	ft_list_insert(&env->list, env->list.last, &new->conn);
	return (0);
}
