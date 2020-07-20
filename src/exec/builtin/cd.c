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

#include <unistd.h>
#include <limits.h>

#include <ft_printf.h>
#include <libft.h>

#include "../../env/env.h"

static uint8_t	cd(t_env *const env,
				const char *const old_path,
				const char *const new_path)
{
	if (chdir(new_path) == -1)
	{
		return (ft_eprintf(1, "cd: unable to change dir '%s'\n", new_path));
	}
	if (env_set(env, "OLDPWD", old_path) == -1)
	{
		return (ft_eprintf(2, "cd: could not set $OLDPWD\n"));
	}
	if (env_set(env, "PWD", new_path) == -1)
	{
		return (ft_eprintf(2, "cd: could not set $PWD\n"));
	}
	return (0);
}

uint8_t			builtin_cd(int argc, char **argv, t_env *const env)
{
	char	old_path[PATH_MAX];
	char	new_path[PATH_MAX];

	if (getcwd(old_path, PATH_MAX) == NULL)
		return (ft_eprintf(1, "cd: getcwd syscall failed\n"));
	if (argc > 2)
		return (ft_eprintf(1, "cd: to many arguments\n"));
	if (argc == 1)
	{
		if (env_get_unsafe(env, "HOME") == NULL)
			return (ft_eprintf(1, "cd: $HOME not set\n"));
		ft_strlcpy(new_path, env_get_unsafe(env, "HOME"), PATH_MAX);
	}
	else if (ft_strcmp(argv[1], "-") == 0)
	{
		if (env_get_unsafe(env, "OLDPWD") == NULL)
			return (ft_eprintf(1, "cd: $OLDPWD not set\n"));
		ft_strlcpy(new_path, env_get_unsafe(env, "OLDPWD"), PATH_MAX);
		ft_printf("%s\n", new_path);
	}
	else
		ft_strlcpy(new_path, argv[1], PATH_MAX);
	return (cd(env, old_path, new_path));
}
