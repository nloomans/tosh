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

t_error		input_read(char **dest,
				const struct s_input_formatted_string *prompt)
{
	t_error						error;
	struct s_term_pos			term_size;
	struct s_input__state		state;

	(void)dest;

	error = input__configure(INPUT__CONFIGURE_SETUP);
	if (is_error(error))
	{
		return (errorf("failed to configure terminal for interactive input: %s",
			error.msg));
	}

	ft_memset(&state, '\0', sizeof(state));
	state.cursor_position = 100;
	state.buffer = "echo 'this is a very long line which does not fit within the 80 characters of a standard terminal.'; echo 'this is a very long line which does not fit within the 80 characters of a standard terminal.";

	// TODO: create a real event loop
	while (true)
	{
		if (g_input__sigwinch == 0)
			continue ;
		g_input__sigwinch--;
		if (term_getsize(&term_size) == -1)
			return (errorf("unable to get terminal size"));
		state.terminal_columns = term_size.column;
		input__draw(state, prompt);
	}

	error = input__configure(INPUT__CONFIGURE_RESTORE);
	if (is_error(error))
	{
		return (errorf("failed to restore terminal to previous state: %s",
			error.msg));
	}
	return (error_none());
}
