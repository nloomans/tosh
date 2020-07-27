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

#include "private.h"

t_error		term__handle_resize(t_term *self)
{
	t_error error;

	if (term_getsize(&self->terminal_size) == -1)
		return (errorf("unable to get terminal size"));
	term__send("rc");
	error = term__getcursor(&self->cursor_pos);
	if (is_error(error))
		return (errorf("unable to get cursor position: %s", error.msg));
	return (error_none());
}
