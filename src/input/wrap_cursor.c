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
#include "private.h"

struct s_term_pos	input__wrap_cursor(
						size_t terminal_width,
						size_t prompt_width,
						size_t cursor_pos)
{
	size_t				i;
	struct s_term_pos	pos;

	// TODO: calculate the cursor position when the prompt itself wrapped as
	// well.
	assert(prompt_width <= terminal_width);
	i = 0;
	pos.row = 0;
	pos.column = prompt_width;
	while (i < cursor_pos)
	{
		i++;
		pos.column++;
		if (pos.column == terminal_width)
		{
			pos.column = 0;
			pos.row++;
		}
	}
	return (pos);
}
