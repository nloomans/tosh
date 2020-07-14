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

#include "private.h"
#include "builtin/builtin.h"

static const struct s_builtin_tbl g_table[] = {
	{
		.name = "cd",
		.ptr = &builtin_cd,
	},
	{
		.name = "setenv",
		.ptr = &builtin_setenv,
	},
	{
		.name = "unsetenv",
		.ptr = NULL,
	},
	{
		.name = "env",
		.ptr = NULL,
	},
	{
		.name = "echo",
		.ptr = &builtin_echo,
	},
	{
		.name = "exit",
		.ptr = &builtin_exit,
	},
};

t_builtin	*exec__identify_builtin(const char *const name)
{
	size_t	iter;

	iter = 0;
	while (iter < (sizeof(g_table) / sizeof(struct s_builtin_tbl)))
	{
		if (ft_strequ(g_table[iter].name, name))
		{
			return (g_table[iter].ptr);
		}
		iter++;
	}
	return (NULL);
}
