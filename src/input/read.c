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
#include "../error/error.h"
#include "../term/term.h"
#include "private.h"

#include <unistd.h>
#include <ft_printf.h>

static t_error	event_loop(const struct s_input_formatted_string *prompt)
{
	t_error					error;
	struct s_input__state	state;
	t_input__action			action;

	ft_memset(&state, '\0', sizeof(state));
	state.cursor_position = 100;
	state.buffer = "echo 'this is a very long line which does not fit within the 80 characters of a standard terminal.'; echo 'this is a very long line which does not fit within the 80 characters of a standard terminal.";

	error = input__action_update_width(&state);
	if (is_error(error))
		return (errorf("failed to get terminal width: %s", error.msg));
	input__draw(state, prompt);
	while (true)
	{
		error = input__next_action(&action);
		if (is_error(error))
			return (errorf("failed to get next action: %s", error.msg));
		if (action == NULL)
			continue ;
		error = (*action)(&state);
		if (is_error(error))
			return (errorf("failed to run action: %s", error.msg));
		input__draw(state, prompt);
	}
	// TODO: exit condition
}

t_error		input_read(char **dest,
				const struct s_input_formatted_string *prompt)
{
	t_error						error;

	(void)dest;

	error = input__configure(INPUT__CONFIGURE_SETUP);
	if (is_error(error))
	{
		return (errorf("tosh: failed to configure terminal for interactive "
			"input: %s", error.msg));
	}
	error = event_loop(prompt);
	if (is_error(error))
	{
		input__configure(INPUT__CONFIGURE_RESTORE); // best effort
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
