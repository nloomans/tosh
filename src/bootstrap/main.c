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

#include "../input/input.h"
#include "../history/history.h"
#include "private.h"

static int	debug(const char *module)
{
	if (ft_strcmp(module, "input") == 0)
		return (input_debug());
	else if (ft_strcmp(module, "history") == 0)
		return (history_debug());
	else
		return (ft_eprintf(1, "no debug main for module '%s'", module));
}

int			main(int argc, char **argv, char **envp)
{
	struct s_ft_getopt	opt;

	opt = ft_getopt_default();
	while (ft_getopt(&opt, argc, argv, "vhd:"))
	{
		if (opt.opt == 'v')
		{
			ft_printf("tosh version " VERSION "\n");
			return (0);
		}
		else if (opt.opt == 'd')
			return (debug(opt.arg));
		else if (opt.opt == 'h')
			return (ft_eprintf(0, HELP_STR));
	}
	if (opt.illegal)
		return (ft_eprintf(1, HELP_STR));
	tosh(envp);
}
