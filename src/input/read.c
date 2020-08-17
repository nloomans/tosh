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
#include <unistd.h>
#include <ft_printf.h>

#include "../error/error.h"
#include "../term/term.h"
#include "private.h"

static t_error	event_loop(struct s_input_read_result *dest,
					t_term *term,
					struct s_input__persistent *persistent_state,
					struct s_term_formatted_string prompt)
{
	t_error						error;
	struct s_input__state		state;
	bool						did_invalidate;

	ft_memset(&state, '\0', sizeof(state));
	state.buffer = ft_strnew(0);
	if (state.buffer == NULL)
		return (errorf("out of memory"));
	state.select_start = -1;
	state.persistent = persistent_state;
	input__draw(state, term, prompt);
	while (state.finished == INPUT_EXIT_REASON_NONE)
	{
		error = input__run_next_action(&state, term, &did_invalidate, read);
		if (is_error(error))
			return (errorf("failed to run next action: %s", error.msg));
		if (did_invalidate)
			input__draw(state, term, prompt);
	}
	*dest = (struct s_input_read_result){state.finished, state.buffer};
	ft_dprintf(STDERR_FILENO, "\n");
	return (error_none());
}

static t_error	setup_persistent_state(bool *is_static_setup,
					struct s_input__persistent *persistent_state)
{
	t_error	error;

	if (*is_static_setup)
		return (error_none());
	persistent_state->copied_text = ft_strnew(0);
	if (persistent_state->copied_text == NULL)
		return (errorf("out of memory"));
	error = history_create(&persistent_state->history);
	if (is_error(error))
	{
		ft_dprintf(STDERR_FILENO,
			"tosh: failed to enable history support: %s\n", error.msg);
	}
	*is_static_setup = true;
	return (error_none());
}

t_error			input_read(struct s_input_read_result *dest,
					const char *prompt, size_t prompt_width)
{
	t_error								error;
	static bool							is_static_setup;
	static struct s_input__persistent	persistent_state;
	t_term								*term;

	error = setup_persistent_state(&is_static_setup, &persistent_state);
	if (is_error(error))
		return (errorf("failed to setup persistent state: %s", error.msg));
	error = input__configure(&term, INPUT__CONFIGURE_SETUP);
	if (is_error(error))
		return (errorf("failed to enable interactive input: %s", error.msg));
	error = event_loop(dest, term, &persistent_state,
		(struct s_term_formatted_string){prompt, prompt_width});
	if (is_error(error))
	{
		*dest = (struct s_input_read_result){INPUT_EXIT_REASON_CANCEL, NULL};
		ft_dprintf(STDERR_FILENO, "tosh: %s\n", error.msg);
	}
	error = input__configure(&term, INPUT__CONFIGURE_RESTORE);
	if (is_error(error))
		ft_dprintf(STDERR_FILENO,
			"tosh: failed to restore terminal to previous state: %s\n",
			error.msg);
	return (error_none());
}
