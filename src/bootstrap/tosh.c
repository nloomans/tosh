/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: aholster <aholster@student.codam.nl>          +:+                    */
/*       ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*       nloomans <nloomans@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>
#include <unistd.h>
#include "../error/error.h"
#include "../term/term.h"

void	tosh(void)
{
	t_error				error;
	struct s_term_pos	pos;

	term_init(getenv("TERM"));
	term_configure(TERM_CONFIGURE_SETUP);
	error = term_getcursor(&pos);
	if (is_error(error))
	{
		ft_dprintf(STDERR_FILENO, "unable to get cursor pos: %s\n", error.msg);
		return ;
	}
	ft_printf("pos: row %u column %u\n", pos.row, pos.column);
	term_configure(TERM_CONFIGURE_RESTORE);
}
