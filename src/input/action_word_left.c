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

t_error		input__action_word_left(struct s_input__state *state)
{
	if (state->cursor_position == 0)
		return (error_none());
	while (state->cursor_position > 0 &&
		ft_isspace(state->buffer[state->cursor_position - 1]))
	{
		state->cursor_position--;
	}
	while (state->cursor_position > 0 &&
		!ft_isspace(state->buffer[state->cursor_position - 1]))
	{
		state->cursor_position--;
	}
	return (error_none());
}
