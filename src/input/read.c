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

t_error		input_read(char **dest, const char *prompt, size_t prompt_width)
{
	struct s_input__state		state;
	struct s_input__draw_state	draw_state;

	(void)dest;
	(void)prompt;
	(void)prompt_width;

	ft_memset(&state, '\0', sizeof(state));
	state.terminal_rows = 81;
	state.cursor_position = 42;
	state.buffer = "echo 'this is a very long line which does not fit within the 80 characters of a standard terminal.'";
	ft_memset(&draw_state, '\0', sizeof(draw_state));
	draw_state.cursor_row = 0;
	draw_state.claimed_columns = 0;

	term_configure(TERM_CONFIGURE_SETUP);

	input__draw(&draw_state, state);
	sleep(5);
	ft_dprintf(STDERR_FILENO, "\n");

	term_configure(TERM_CONFIGURE_RESTORE);
	return (error_none());
}
