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

#include <ft_printf.h>

#include "../../env/env.h"

uint8_t		builtin_unsetenv(int argc, char **argv, t_env *const env)
{
	int	index;

	if (argc <= 1)
	{
		return (ft_eprintf(1, "Usage: unsetenv <key> ...\n"));
	}
	else
	{
		index = 1;
		while (index < argc)
		{
			env_unset(env, argv[index]);
			index++;
		}
		return (0);
	}
}
