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

static int		free_new(struct s_env_pair	*new)
{
	ft_strdel(&new->key);
	ft_strdel(&new->value);
	ft_memdel((void **)&new);
	return (-1);
}

int				env_from_envp(t_env *env, char **envp)
{
	size_t				i;
	struct s_env_pair	*new;
	size_t				equal_index;

	i = 0;
	while (envp[i] != '\0')
	{
		new = ft_memalloc(sizeof(*new));
		if (new == NULL)
		{
			env_list_delete(env);
			return (-1);
		}
		assert(ft_strchr(envp[i], '=') != NULL);
		equal_index = ft_strchr(envp[i], '=') - envp[i];
		new->key = ft_strsub(envp[i], 0, equal_index);
		new->value = ft_strdup(&envp[i][equal_index + 1]);
		if (new->key == NULL || new->value == NULL)
		{
			return (free_new(new));
		}
		ft_list_insert(&env->list, env->list.last, &new->conn);
		i++;
	}
	return (0);
}
