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

#include <termios.h>
#include <unistd.h>
#include <term.h>

#include "private.h"
#include "../error/error.h"

/*
** Modes changed:
** - ~ECHO: Disable the printing of keypresses into the terminal.
** - ~ICANON: Read input char-by-char instead of line-by-line.
** - ~ISIG: Read CTRL+C, CTRL+\, CTRL+Z, CTRL+Y directly instead if firing a
**   signal. We only care about CTRL+C.
** - VIM = 0: Read a minimum bytes to read to 0 bytes.
** - VTIME = 1: A maximum of 100ms per keypress;
*/

static t_error	configure(t_term *term)
{
	struct termios			new;

	if (tcgetattr(STDIN_FILENO, &term->original_termios) == -1)
		return (errorf("tcgetattr failed"));
	new = term->original_termios;
	new.c_lflag &= ~(ECHO | ICANON | ISIG);
	new.c_cc[VMIN] = 0;
	new.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &new) == -1)
		return (errorf("tcsetattr failed"));
	return (error_none());
}

t_error			term_setup(t_term **out, const char *term_env)
{
	t_error					error;
	static t_term			term;

	if (tgetent(NULL, term_env) != 1)
	{
		if (tgetent(NULL, "xterm") != 1)
			return (errorf("tgetent failed: unknown $TERM and xterm is invalid"));
	}
	error = configure(&term);
	if (is_error(error))
		return (error);
	if (term_getsize(&term.terminal_size) == -1)
		return (errorf("failed to get terminal size"));
	term__getcursor(&term.cursor_pos);
	term.saved_pos = term.cursor_pos;
	term.handle_resize = term__handle_resize;
	term.cursor_goto = term__cursor_goto;
	term.print = term__print;
	term.clear_to_end = term__clear_to_end;
	term__send("sc");
	*out = &term;
	return (error_none());
}
