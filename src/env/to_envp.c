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
#include "ft_printf.h"

char					**env_to_envp(t_env *const env)
{
	size_t					i;
	t_list_conn				*iter;
	const struct s_env_pair	*temp;
	char					**env_arr;

	i = 0;
	iter = env->list.first;
	env_arr = ft_memalloc(sizeof(char *) * (env->list.len + 1));
	if (env_arr == NULL)
		return (NULL);
	while (i < env->list.len)
	{
		assert(iter != NULL);
		temp = unpack_env(iter);
		ft_asprintf(&env_arr[i], "%s=%s", temp->key, temp->value);
		if (env_arr[i] == NULL)
		{
			ft_arraydel((void ***)&env_arr, ft_memdel);
			return (NULL);
		}
		iter = iter->next;
		i++;
	}
	env_arr[i] = NULL;
	return (env_arr);
}
