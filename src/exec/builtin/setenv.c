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

#include <libft.h>
#include <ft_printf.h>

#include "../../env/env.h"

static char	*find_key_limit(char *iter)
{
	if (ft_isdigit(iter[0]) || iter[0] == '=')
	{
		return (NULL);
	}
	while (*iter && env_is_key_char(*iter))
	{
		iter++;
	}
	if (*iter == '=')
	{
		return (iter);
	}
	return (NULL);
}

static int	split_kvp_str(char *const key, t_env *const env)
{
	char	*sep;

	sep = find_key_limit(key);
	if (sep == NULL)
	{
		return (ft_eprintf(5, "setenv: badly formatted key %s\n", key));
	}
	else
	{
		*sep = '\0';
		if (env_set(env, key, sep + 1) == -1)
		{
			return (ft_eprintf(5, "minishell: setenv: failed to edit env\n"));
		}
	}
	return (0);
}

uint8_t		builtin_setenv(int argc, char **argv, t_env *const env)
{
	int		index;
	int		err;

	if (argc == 1)
	{
		return (ft_eprintf(5, "Usage: setenv <key>=<value> ...\n"));
	}
	err = 0;
	index = 1;
	while (index < argc)
	{
		if (split_kvp_str(argv[index], env) == -1)
		{
			err = 1;
		}
		index++;
	}
	return (err);
}
