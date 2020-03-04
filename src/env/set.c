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
#include <assert.h>

int						env_set(t_env *const env,
							char const *const key,
							char const *const value)
{
	struct s_env_pair	*new;

	assert(key != NULL || value != NULL);
	env_unset(env, key);
	new = (struct s_env_pair *)ft_memalloc(sizeof(*new));
	if (new == NULL)
		return (-1);
	new->key = ft_strdup(key);
	if (new->key == NULL)
	{
		ft_memdel((void **)new);
		return (-1);
	}
	new->value = ft_strdup(value);
	if (new->value == NULL)
	{
		ft_strdel(&new->key);
		ft_memdel((void **)new);
		return (-1);
	}
	ft_list_insert(&env->list, env->list.last, &new->conn);
	return (0);
}
