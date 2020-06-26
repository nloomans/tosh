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

static t_error	event_loop(char **dest, t_term *term, t_history *history,
					struct s_term_formatted_string prompt)
{
	t_error						error;
	struct s_input__state		state;
	bool						did_invalidate;

	ft_memset(&state, '\0', sizeof(state));
	state.buffer = ft_strnew(0);
	if (state.buffer == NULL)
		return (errorf("out of memory"));
	state.history = history;
	input__draw(state, term, prompt);
	while (!state.finished)
	{
		error = input__run_next_action(&state, term, &did_invalidate, read);
		if (is_error(error))
			return (errorf("failed to run next action: %s", error.msg));
		if (did_invalidate)
			input__draw(state, term, prompt);
	}
	*dest = state.buffer;
	ft_dprintf(STDERR_FILENO, "\n");
	return (error_none());
}

t_error			input_read(char **dest, t_history *history,
					struct s_term_formatted_string prompt)
{
	t_error						error;
	t_term						*term;

	error = input__configure(&term, INPUT__CONFIGURE_SETUP);
	if (is_error(error))
	{
		return (errorf("failed to configure terminal for interactive input: %s",
			error.msg));
	}
	error = event_loop(dest, term, history, prompt);
	if (is_error(error))
	{
		input__configure(&term, INPUT__CONFIGURE_RESTORE);
		return (errorf("tosh: %s", error.msg));
	}
	error = input__configure(&term, INPUT__CONFIGURE_RESTORE);
	if (is_error(error))
	{
		return (errorf("failed to restore terminal to previous state: %s",
			error.msg));
	}
	return (error_none());
}
