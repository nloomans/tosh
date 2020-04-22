/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tosh - 21 Shell                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include "ft_printf.h"

static int				fill_new(struct s_env_pair *const new, char *const envp)
{
	size_t				equal_index;

	if (ft_strchr(envp, '=') == NULL)
	{
		ft_dprintf(2, "Warning: env: '%s', no '=' present\n", envp);
		return (1);
	}
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

static int				fill_all(struct s_env *const env, char **const envp)
{
	size_t				i;
	int					ret;
	struct s_env_pair	*new;

	i = 0;
	while (envp[i] != NULL)
	{
		new = ft_memalloc(sizeof(*new));
		if (new == NULL)
			return (-1);
		ret = fill_new(new, envp[i]);
		if (ret == -1)
		{
			ft_memdel((void **)&new);
			return (-1);
		}
		if (ret == 0)
		{
			ft_list_insert(&env->list, env->list.last, &new->conn);
		}
		i++;
	}
	return (0);
}

t_env					*env_from_envp(char **const envp)
{
	struct s_env		*env;

	env = ft_memalloc(sizeof(*env));
	if (env == NULL)
		return (NULL);
	if (fill_all(env, envp) == -1)
	{
		env_delete(&env);
		return (NULL);
	}
	return (env);
}
