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

static void		add(struct s_env_list **start_lst, struct s_env_list *new)
{
	struct s_env_list	*temp;

	if (*start_lst == NULL)
	{
		*start_lst = new;
		new->next = NULL;
	}
	else
	{
		temp = *start_lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->next = NULL;
	}
}

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
		add(&env->list, new);
		i++;
	}
	return (0);
}
