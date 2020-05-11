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
	if (g_input__sigwinch > 0)
	{
		g_input__sigwinch--;
		return (SIGWINCH);
	}
	return (0);
}

static t_error					run_next_signal(struct s_input__state *state,
									int signum)
{
	if (signum == SIGWINCH)
		return (input__action_update_width(state));
	assert(!"unknown signum");
}

static bool						read_seq_is(struct s_input__read_seq read_seq,
									enum e_input__read_type type, char c)
{
	return (read_seq.type == type && read_seq.c == c);
}

static t_error					run_next_read_seq(struct s_input__state *state,
									struct s_input__read_seq read_seq)
{
	if (read_seq_is(read_seq, INPUT__READ_TYPE_ESC, 'D'))
		return (input__action_left(state));
	if (read_seq_is(read_seq, INPUT__READ_TYPE_ESC, 'C'))
		return (input__action_right(state));
	if (read_seq.type == INPUT__READ_TYPE_REG && ft_isprint(read_seq.c))
		return (input__action_insert(state, read_seq.c));
	return (error_none());
}

t_error							input__run_next_action(
									struct s_input__state *state,
									bool *did_invalidate)
{
	t_error						error;
	int							signum;
	struct s_input__read_seq	read_seq;

	*did_invalidate = true;
	signum = next_signal();
	if (signum != 0)
	{
		return (run_next_signal(state, signum));
	}
	error = input__read_seq(&read_seq);
	if (is_error(error))
		return (errorf("failed to read sequence: %s", error.msg));
	if (read_seq.type != INPUT__READ_TYPE_NONE)
	{
		return (run_next_read_seq(state, read_seq));
	}
	*did_invalidate = false;
	return (error_none());
}
