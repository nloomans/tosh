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

#include <stdlib.h>

#include <libft.h>
#include <ft_printf.h>

#include "../../env/env.h"

uint8_t		builtin_exit(int argc, char **argv, t_env *const env)
{
	int		num;

	if (argc <= 2)
	{
		if (argc == 2)
		{
			num = ft_atoi(argv[1]);
		}
		else
		{
			num = env_get_exit_status(env);
		}
		exit(num);
	}
	else
	{
		return(ft_eprintf(1, "exit: too many arguments\n"));
	}
}
