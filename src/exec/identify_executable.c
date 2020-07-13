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

static t_error		find_command_path(char path[PATH_MAX],
						const t_env *const env,
						char const *const name)
{
	char						*iter = env_get(env, "PATH");
	int							sub_len;
	const size_t				name_len = ft_strlen(name);

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
			if (sub_len + name_len >= PATH_MAX)
				return (errorf("%s: File name too long", name));
			ft_snprintf(path, PATH_MAX, "%.*s/%s", sub_len, iter, name);
			if (access(path, F_OK | X_OK) == 0)
				return (error_none());
			iter += sub_len;
		}
		ft_bzero(path, PATH_MAX);
	}
	return (errorf("%s: command not found", name));
}

static t_error		identify_executable_type(char path[PATH_MAX],
						const t_env *env,
						char const *const name)
{
	if (ft_strchr(name, '/') == NULL)
	{
		return (find_command_path(path, env, name));
	}
	else
	{
		if (ft_strlen(name) >= PATH_MAX)
		{
			return (errorf("%s: File name too long", name));
		}
		if (access(name, F_OK) != 0)
		{
			return (errorf("%s: No such file or directory", name));
		}
		ft_memcpy(path, name, ft_strlen(name) + 1);
		return (error_none());
	}
}

void				exec__identify_executable(
						const struct s_program_prereq *const all_arg,
						const t_env *const env)
{
	char	path[PATH_MAX];
	t_error	err;

	err = identify_executable_type(path, env, all_arg->argv[0]);
	if (is_error(err))
	{
		ft_dprintf(STDERR_FILENO, "tosh: %s\n", err.msg);
		return ;
	}
	dprintf(2, "identified as '%s'\n", path);
	if (access(path, X_OK) == -1)
	{
		ft_dprintf(STDERR_FILENO, "tosh: %s: no execute permission\n", path);
		return ;
	}
	if (execve(path, all_arg->argv, all_arg->envp) == -1)
	{
		ft_dprintf(STDERR_FILENO, "tosh: %s: execve syscall failed\n", path);
	}
}
