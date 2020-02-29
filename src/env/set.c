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

static void				add(struct s_env_list **start_lst,
							struct s_env_list *new)
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

int						env_set(t_env *env, char *key, char *value)
{
	struct s_env_list	*new;

	if (key && value)
	{
		env_unset(env, key);
		new = (struct s_env_list *)ft_memalloc(sizeof(*new));
		if (new == NULL)
			return (-1);
		new->key = ft_strdup(key);
		new->value = ft_strdup(value);
		if (new->key == NULL || new->value == NULL)
			return (-1);
		add(&env->list, new);
	}
	else
		return (-1);
	return (0);
}
