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

#include <term.h>
#include <unistd.h>

#include "private.h"

static int	putchar_stderr(int c)
{
	return (write(STDERR_FILENO, &c, 1));
}

void		term__send(const char *entry)
{
	tputs(tgetstr((char *)entry, NULL), 1, putchar_stderr);
}
