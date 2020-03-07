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

static int				fill_new(struct s_env_pair *new, char *envp)
{
	size_t				equal_index;

	equal_index = ft_strchr(envp, '=') - envp;
	new->key = ft_strsub(envp, 0, equal_index);
	new->value = ft_strdup(&envp[equal_index + 1]);
	if (new->key == NULL || new->value == NULL)
	{
		ft_strdel(&new->key);
		ft_strdel(&new->value);
		ft_memdel((void **)&new);
		return (-1);
	}
	return (0);
}

int						env_from_envp(t_env *env, char **envp)
{
	size_t				i;
	struct s_env_pair	*new;

	i = 0;
	while (envp[i] != '\0')
	{
		new = ft_memalloc(sizeof(*new));
		if (new == NULL)
		{
			env_list_delete(env);
			return (-1);
		}
		if (fill_new(new, envp[i]) == -1)
			return (-1);
		ft_list_insert(&env->list, env->list.last, &new->conn);
		i++;
	}
	return (0);
}
