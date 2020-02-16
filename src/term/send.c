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

#include <term.h>
#include <unistd.h>
#include "priv.h"

static int	putchar_stderr(int c)
{
	return (write(STDERR_FILENO, &c, 1));
}

void		term__send(const char *entry)
{
	tputs(tgetstr((char *)entry, NULL), 0, putchar_stderr);
}
