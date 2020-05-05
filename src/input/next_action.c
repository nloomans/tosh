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

#include "private.h"

static const t_input__action	key_map[3][256] = {
	[INPUT__READ_TYPE_ESC] = {
		['D'] = input__action_left,
		['C'] = input__action_right,
	},
};

t_error							input__next_action(t_input__action *action)
{
	t_error						error;
	struct s_input__read_seq	read_seq;

	*action = NULL;
	if (g_input__sigwinch > 0)
	{
		g_input__sigwinch--;
		*action = input__action_update_width;
	}
	error = input__read_seq(&read_seq);
	if (is_error(error))
		return (errorf("failed to read input: %s", error));
	if (read_seq.type != INPUT__READ_TYPE_NONE)
		*action = key_map[read_seq.type][(unsigned char)read_seq.c];
	return (error_none());
}
