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

#include "private.h"

static int						next_signal(void)
{
	if (g_input__sigwinch)
	{
		g_input__sigwinch = 0;
		return (SIGWINCH);
	}
	return (0);
}

static t_error					run_next_signal(t_term *term, int signum)
{
	if (signum == SIGWINCH)
		return (input__action_resize(term));
	assert(!"unknown signum");
}

static t_error					run_next_keypress(struct s_input__state *state,
									struct s_input__keypress keypress)
{
	if (keypress.type == INPUT__READ_ARROW_LEFT)
		return (input__action_left(state));
	if (keypress.type == INPUT__READ_ARROW_RIGHT)
		return (input__action_right(state));
	if (keypress.type == INPUT__READ_BACKSPACE)
		return (input__action_backspace(state));
	if (keypress.type == INPUT__READ_RETURN)
		return (input__action_return(state));
	if (keypress.type == INPUT__READ_TEXT)
		return (input__action_insert(state, keypress.c));
	assert(!"unhandled keypress type");
}

t_error							input__run_next_action(
									struct s_input__state *state,
									t_term *term,
									bool *did_invalidate,
									t_read_func read_func)
{
	int							signum;
	struct s_input__keypress	keypress;

	*did_invalidate = true;
	signum = next_signal();
	if (signum != 0)
	{
		return (run_next_signal(term, signum));
	}
	if (input__read_keypress(&keypress, read_func) == -1)
		return (errorf("failed to read keypress"));
	if (keypress.type != INPUT__READ_NONE)
	{
		return (run_next_keypress(state, keypress));
	}
	*did_invalidate = false;
	return (error_none());
}
