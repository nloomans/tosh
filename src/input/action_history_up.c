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

t_error		input__action_history_up(struct s_input__state *state)
{
	char *new_buffer;

	if (!state->persistent->history)
		return (error_none());
	new_buffer = history_up(state->persistent->history);
	if (new_buffer == NULL)
		return (error_none());
	input__action_select_cancel(state);
	ft_strreplace(&state->buffer, new_buffer);
	state->cursor_position = ft_strlen(state->buffer);
	return (error_none());
}
