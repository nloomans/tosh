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

t_error		input__action_update_width(struct s_input__state *state)
{
	struct s_term_pos		term_size;

	if (term_getsize(&term_size) == -1)
		return (errorf("unable to get terminal size"));
	state->terminal_columns = term_size.column;
	return (error_none());
}
