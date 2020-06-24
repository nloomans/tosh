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
#include <unistd.h>

#include "private.h"

void				term__cursor_goto(t_term *self, struct s_term_pos new_pos)
{
	ft_dprintf(STDERR_FILENO, "\033[%u;%uH",
		new_pos.row + 1, new_pos.column + 1);
	self->cursor_pos = new_pos;
}
