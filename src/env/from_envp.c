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
#include "env.h"

int				env_from_envp(t_env *env, char **envp)
{
	size_t				i;
	struct s_env_list	*new;
	size_t				equal_index;

	i = 0;
	while (envp[i] != '\0')
	{
		new = (struct s_env_list *)ft_memalloc(sizeof(*new));
		if (new == NULL)
			return (-1);
		assert(ft_strchr(envp[i], '=') != NULL);
		equal_index = ft_strchr(envp[i], '=') - envp[i];
		new->key = ft_strndup(envp[i], equal_index);
		new->value = ft_strdup(&envp[i][equal_index + 1]);
		if (new->key == NULL || new->value == NULL)
			return (-1);
		ft_list_insert(&env->meta, env->meta.last, &new->conn);
		i++;
	}
	return (0);
}
