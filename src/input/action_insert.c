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

#include <libft.h>
#include <ft_printf.h>
#include "private.h"

t_error					input__action_insert(struct s_input__state *state,
							char c)
{
	char	*new;

	ft_asprintf(&new, "%.*s%c%s",
		state->cursor_position, state->buffer,
		c,
		state->buffer + state->cursor_position);
	if (new == NULL)
		return (errorf("out of memory"));
	ft_strreplace(&state->buffer, new);
	state->cursor_position++;
	return (error_none());
}
