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

static void				correct_positions(t_term *self)
{
	size_t				move_up_amount;
	struct s_term_pos	cursor_pos;

	if (self->cursor_pos.row >= self->terminal_size.row)
	{
		move_up_amount = self->cursor_pos.row + 1 - self->terminal_size.row;
		self->saved_pos.row -= move_up_amount;
		self->cursor_pos.row -= move_up_amount;
		cursor_pos = self->cursor_pos;
		self->cursor_goto(self, self->saved_pos);
		term__send("sc");
		self->cursor_goto(self, cursor_pos);
	}
}

void					term__print(t_term *self,
							struct s_term_formatted_string formatted_string)
{
	ft_dprintf(STDERR_FILENO, "%s", formatted_string.string);
	self->cursor_pos = term_wrap(self->terminal_size.column, self->cursor_pos,
		formatted_string.width);
	correct_positions(self);
}
