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
#include <libft.h>
#include <unistd.h>
#include <ft_printf.h>

#include "../error/error.h"
#include "../term/term.h"
#include "private.h"

static t_error	event_loop(char **dest,
					const struct s_input_formatted_string *prompt)
{
	t_error						error;
	struct s_input__state		state;
	bool						did_invalidate;

	ft_memset(&state, '\0', sizeof(state));
	state.cursor_position = 0;
	state.buffer = ft_strnew(0);
	error = input__action_update_width(&state);
	if (is_error(error))
		return (errorf("failed to get terminal width: %s", error.msg));
	input__draw(state, prompt);
	while (!state.finished)
	{
		error = input__run_next_action(&state, &did_invalidate, read);
		if (is_error(error))
			return (errorf("failed to run next action: %s", error.msg));
		if (did_invalidate)
			input__draw(state, prompt);
	}
	*dest = state.buffer;
	ft_dprintf(STDERR_FILENO, "\n");
	return (error_none());
}

t_error			input_read(char **dest,
					const struct s_input_formatted_string *prompt)
{
	t_error						error;

	error = input__configure(INPUT__CONFIGURE_SETUP);
	if (is_error(error))
	{
		return (errorf("failed to configure terminal for interactive input: %s",
			error.msg));
	}
	error = event_loop(dest, prompt);
	if (is_error(error))
	{
		input__configure(INPUT__CONFIGURE_RESTORE);
		return (errorf("tosh: %s", error.msg));
	}
	error = input__configure(INPUT__CONFIGURE_RESTORE);
	if (is_error(error))
	{
		return (errorf("failed to restore terminal to previous state: %s",
			error.msg));
	}
	return (error_none());
}
