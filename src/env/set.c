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

int						env_set(t_env *const env,
							char const *const key,
							char const *const value)
{
	struct s_env_list	*new;

	if (key == NULL || value == NULL)
		return (-1);
	env_unset(env, key);
	new = (struct s_env_list *)ft_memalloc(sizeof(*new));
	if (new == NULL)
		return (-1);
	new->key = ft_strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (-1);
	}
	new->value = ft_strdup(value);
	if (new->value == NULL)
	{
		ft_strdel(&new->key);
		free(new);
		return (-1);
	}
	ft_list_insert(&env->meta, env->meta.last, &new->conn);
	return (0);
}
