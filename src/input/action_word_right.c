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

t_error		input__action_word_right(struct s_input__state *state)
{
	size_t	buffer_len;

	buffer_len = ft_strlen(state->buffer);
	while (state->cursor_position < buffer_len &&
		ft_isspace(state->buffer[state->cursor_position]))
	{
		state->cursor_position++;
	}
	while (state->cursor_position < buffer_len &&
		!ft_isspace(state->buffer[state->cursor_position]))
	{
		state->cursor_position++;
	}
	return (error_none());
}
