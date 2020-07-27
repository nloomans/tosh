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

t_normal_action *g_action_type_table[] = {
	[INPUT__READ_ARROW_LEFT] = input__action_left,
	[INPUT__READ_ARROW_RIGHT] = input__action_right,
	[INPUT__READ_ARROW_UP] = input__action_history_up,
	[INPUT__READ_ARROW_DOWN] = input__action_history_down,
	[INPUT__READ_HOME] = input__action_max_left,
	[INPUT__READ_END] = input__action_max_right,
	[INPUT__READ_BACKSPACE] = input__action_backspace,
	[INPUT__READ_RETURN] = input__action_return,
	[INPUT__READ_TAB] = input__action_tab,
};

t_normal_action *g_action_control_table[128] = {
	['A'] = input__action_max_left,
	['D'] = input__action_done,
	['E'] = input__action_max_right,
	['X'] = input__action_cut,
	['V'] = input__action_paste,
};

static t_error					run_next_keypress(struct s_input__state *state,
									struct s_input__keypress keypress)
{
	if (keypress.modifier & INPUT__MODIFIER_CONTROL)
	{
		if (keypress.type == INPUT__READ_ARROW_LEFT)
			return (input__action_word_left(state));
		if (keypress.type == INPUT__READ_ARROW_RIGHT)
			return (input__action_word_right(state));
		if (keypress.type == INPUT__READ_TEXT)
		{
			if (keypress.c == 'C' && state->select_start == -1)
				return (input__action_cancel(state));
			if (keypress.c == 'C' && state->select_start != -1)
				return (input__action_copy(state));
			if (g_action_control_table[(int)keypress.c] != NULL)
				return (g_action_control_table[(int)keypress.c](state));
		}
	}
	else if (keypress.type == INPUT__READ_TEXT)
		return (input__action_insert(state, keypress.c));
	else if (g_action_type_table[keypress.type] != NULL)
		return (g_action_type_table[keypress.type](state));
	return (error_none());
}

t_error							input__run_next_action(
									struct s_input__state *state,
									t_term *term,
									bool *did_invalidate,
									t_read_func read_func)
{
	t_error						error;
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
		if (keypress.modifier & INPUT__MODIFIER_SHIFT)
			input__action_select_start(state);
		error = run_next_keypress(state, keypress);
		if (!(keypress.modifier & INPUT__MODIFIER_SHIFT))
			input__action_select_cancel(state);
		return (error);
	}
	*did_invalidate = false;
	return (error_none());
}
