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

uint8_t		builtin_echo(int argc, char **argv, t_env *const env)
{
	int i;
	int no_newline;

	(void)env;
	if (argc >= 2 && ft_strcmp(argv[1], "-n") == 0)
	{
		no_newline = 1;
		i = 2;
	}
	else
	{
		no_newline = 0;
		i = 1;
	}
	while (i < argc)
	{
		ft_printf("%s", argv[i]);
		if (i < argc - 1)
			ft_printf(" ");
		i++;
	}
	if (!no_newline)
		ft_printf("\n");
	return (0);
}
