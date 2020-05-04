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
	struct s_term_pos			term_size;
	struct s_input__state		state;

	(void)dest;

	ft_memset(&state, '\0', sizeof(state));
	state.cursor_position = 100;
	state.buffer = "echo 'this is a very long line which does not fit within the 80 characters of a standard terminal.'; echo 'this is a very long line which does not fit within the 80 characters of a standard terminal.";

	term_configure(TERM_CONFIGURE_SETUP);

	// The input module works on the assumption that the saved cursor state
	// will remain the same when the terminal emulator resizes stuff. I.e. if
	// the terminal wraps a row into two, the saved cursor position is wrapped
	// together with the text. This seems to work on all terminals I tried
	// except for the builtin VSCode terminal. But zsh has the same issues as
	// our shell on that terminal so it should be fine.
	//
	// TODO: Reposition the cursor to a sensible starting place. The cursor
	// wrapping calculation only works when the saved cursor position has a
	// column of 0.
	term_cursor_move(TERM_MOVE_SAVE);

	while (true)
	{
		if (term_getsize(&term_size) == -1)
			return (errorf("unable to get terminal size"));
		state.terminal_columns = term_size.column;
		input__draw(state, prompt);
		sleep(1);
	}

	term_configure(TERM_CONFIGURE_RESTORE);
	return (error_none());
}
