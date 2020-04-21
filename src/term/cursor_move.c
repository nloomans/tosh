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

#include <assert.h>
#include <unistd.h>
#include <ft_printf.h>
#include "private.h"

void	term_cursor_move(enum e_term_move direction)
{
	if (direction == TERM_MOVE_UP)
		term__send("up");
	else if (direction == TERM_MOVE_DOWN)
		term__send("do");
	else if (direction == TERM_MOVE_LINE_START)
		ft_dprintf(STDERR_FILENO, "\r");
	else if (direction == TERM_MOVE_RIGHT)
		term__send("nd");
	else
		assert(!"invalid direction");
}
