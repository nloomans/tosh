/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tosh-21Shell                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

#include <libft.h>
#include <ft_printf.h>

#include "private.h"

#include <stdio.h>
#include <stdlib.h>
static int		find_command_path(char path[PATH_MAX],
					const t_env *const env,
					char const *const name)
{
	char						*iter = env_get(env, "PATH");
	int							sub_len;

	if (iter != NULL)
	{
		while (*iter != '\0')
		{
			if (*iter == ':')
				iter++;
			if (ft_strchr(iter, ':') != NULL)
				sub_len = ft_strchr(iter, ':') - iter;
			else
				sub_len = ft_strlen(iter);
			ft_snprintf(path, PATH_MAX, "%.*s/%s", sub_len, iter, name);
			if (access(path, F_OK) == 0)
			{
				return (0);
			}
			iter += sub_len;
		}
		ft_bzero(path, PATH_MAX);
	}
	return (-1);
}

static int		identify_executable_type(char path[PATH_MAX],
					const t_env *env,
					char const *const name)
{
	if (ft_strchr(name, '/') == NULL)
	{
		if (find_command_path(path, env, name) == -1)
		{
			//ft_puterr("minishell: %s: command not found\n", name);
			return (-1);
		}
	}
	else
	{
		if (ft_strlen(name) >= PATH_MAX)
		{
			//ft_puterr("minishell: %s: File name too long\n", name);
			return (-1);
		}
		if (access(name, F_OK) != 0)
		{
			//ft_puterr("minishell: %s: No such file or directory\n", name);
			return (-1);
		}
		ft_memcpy(path, name, ft_strlen(name));
	}
	return (0);
}

void		exec__identify_executable(
				const struct s_program_prereq *const all_arg,
				const t_env *const env)
{
	char	path[PATH_MAX];

	identify_executable_type(path, env, all_arg->arg[0]);
	dprintf(2, "identifier found %s\n", path);
	(void)all_arg;
	(void)env;
	dprintf(2, "running: %s....\n", all_arg->arg[0]);
	exit(5);
}
