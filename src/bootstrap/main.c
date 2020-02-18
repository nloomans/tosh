/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: ivan-tey <ivan-tey@student.codam.nl>          +:+                    */
/*       nloomans <nloomans@student.codam.nl>         +#+                     */
/*       aholster <aholster@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <unistd.h>
#include "private.h"

int		main(int argc, char **argv)
{
	struct s_ft_getopt	opt;

	opt = FT_GETOPT_DEFAULT;
	while (ft_getopt(&opt, argc, argv, "vh"))
	{
		if (opt.opt == 'v')
		{
			ft_printf("tosh version " VERSION "\n");
			return (0);
		}
		else if (opt.opt == 'h')
			return (ft_eprintf(0, HELP_STR));
	}
	if (opt.illegal)
		return (ft_eprintf(1, HELP_STR));
	tosh();
}
