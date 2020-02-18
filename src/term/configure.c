/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: aholster <aholster@student.codam.nl>          +:+                    */
/*       ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*       nloomans <nloomans@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include "term.h"

/*
** Modes changed:
** - ~ECHO: Disable the printing of keypresses into the terminal.
** - ~ICANON: Read input char-by-char instead of line-by-line.
** - VIM = 0: Read a minimum bytes to read to 0 bytes.
** - VTIME = 1: A maximum of 100ms per keypress;
*/

void		term_configure(enum e_term_configure_action action)
{
	static struct termios	original;
	struct termios			new;

	if (action == TERM_CONFIGURE_SETUP)
	{
		tcgetattr(STDIN_FILENO, &original);
		new = original;
		new.c_lflag &= ~(ECHO | ICANON);
		new.c_cc[VMIN] = 0;
		new.c_cc[VTIME] = 1;
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &new);
	}
	else
	{
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &original);
	}
}
