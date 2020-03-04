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

static void		free_new(struct s_env_pair	*new)
{
	ft_memdel((void **)new);
	if (new->key != NULL)
		ft_strdel(&new->key);
	if (new->value != NULL)
		ft_strdel(&new->value);
}

int				env_from_envp(t_env *env, char **envp)
{
	size_t				i;
	struct s_env_pair	*new;
	size_t				equal_index;

	i = 0;
	while (envp[i] != '\0')
	{
		new = (struct s_env_pair *)ft_memalloc(sizeof(*new));
		if (new == NULL)
			return (-1);
		assert(ft_strchr(envp[i], '=') != NULL);
		equal_index = ft_strchr(envp[i], '=') - envp[i];
		new->key = ft_strsub(envp[i], 0, equal_index);
		new->value = ft_strdup(&envp[i][equal_index + 1]);
		if (new->key == NULL || new->value == NULL)
		{
			free_new(new);
			return (-1);
		}
		ft_list_insert(&env->list, env->list.last, &new->conn);
		i++;
	}
	return (0);
}
