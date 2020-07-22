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
#include "private.h"

t_error					input__action_tab(struct s_input__state *state)
{
	char	*new;
	size_t	tab_width;

	tab_width = 4 - (state->cursor_position % 4);
	ft_asprintf(&new, "%.*s%*s%s",
		state->cursor_position, state->buffer,
		tab_width, "",
		state->buffer + state->cursor_position);
	if (new == NULL)
		return (errorf("out of memory"));
	ft_strreplace(&state->buffer, new);
	state->cursor_position += tab_width;
	return (error_none());
}
