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

t_error		input__action_return(struct s_input__state *state)
{
	t_error		error;

	if (state->history)
	{
		error = history_push(state->history, state->buffer);
		if (is_error(error))
		{
			return (errorf("failed to save command in history: %s", error.msg));
		}
	}
	state->finished = true;
	return (error_none());
}
