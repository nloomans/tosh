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

char					*env_get(t_env *env, char *key)
{
	char				*value;
	struct s_env_list	*temp;

	temp = env->list;
	while (temp && key)
	{
		if (ft_strequ(temp->key, key) == 1)
		{
			value = ft_strdup(temp->value);
			return (value);
		}
		temp = temp->next;
	}
	return (NULL);
}
