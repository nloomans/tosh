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
#include <stdlib.h>

#include "private.h"

extern volatile sig_atomic_t	g_input__sigwinch;

static void						handle_sigwinch(int signum)
{
	(void)signum;
	g_input__sigwinch = 1;
}

/*
** The input module works on the assumption that the saved cursor state will
** remain the same when the terminal emulator resizes stuff. i.e. if the
** terminal wraps a row into two, the saved cursor position is wrapped together
** with the text. This seems to work on all terminals I tried except for the
** builtin VSCode terminal. But zsh has the same issues as our shell on that
** terminal so it should be fine.
**
** TODO: Reposition the cursor to a sensible starting place. The cursor wrapping
** calculation only works when the saved cursor position has a column of 0.
*/

t_error							input__configure(
									t_term **term,
									enum e_input__configure_action action)
{
	t_error			error;
	static void		(*prev_handler_sigwinch)(int);

	if (action == INPUT__CONFIGURE_SETUP)
	{
		error = term_setup(term, getenv("TERM"));
		if (is_error(error))
			return (errorf("failed to setup terminal: %s", error.msg));
		g_input__sigwinch = 0;
		prev_handler_sigwinch = signal(SIGWINCH, handle_sigwinch);
		assert(prev_handler_sigwinch != SIG_ERR);
	}
	else
	{
		error = term_restore(term);
		if (is_error(error))
			return (errorf("failed to restore terminal: %s", error.msg));
		assert(signal(SIGWINCH, prev_handler_sigwinch) != SIG_ERR);
	}
	return (error_none());
}
