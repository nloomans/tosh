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

char					*fill_env_arr(char const *const key,
									char const *const value)
{
	char				*env_str;
	char				*temp;

	env_str = ft_strdup(key);
	if (env_str == NULL)
		return (NULL);
	temp = env_str;
	env_str = ft_strjoin(temp, "=");
	ft_strdel(&temp);
	if (env_str == NULL)
		return (NULL);
	temp = env_str;
	env_str = ft_strjoin(temp, value);
	ft_strdel(&temp);
	if (env_str == NULL)
		return (NULL);
	return (env_str);
}

char					**env_to_envp(t_env *const env)
{
	size_t				i;
	t_list_conn			*iter;
	struct s_env_list	*temp;
	char				**env_arr;

	i = 0;
	iter = env->meta.first;
	env_arr = (char **)ft_memalloc(sizeof(char *) * (env->meta.len + 1));
	if (env_arr == NULL)
		return (NULL);
	while (i < env->meta.len && iter)
	{
		temp = unpack_env(iter);
		env_arr[i] = fill_env_arr(temp->key, temp->value);
		if (env_arr[i] == NULL)
			return (NULL);
		iter = iter->next;
		i++;
	}
	env_arr[i] = NULL;
	return (env_arr);
}
