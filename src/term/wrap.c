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

struct s_term_pos		term_wrap(size_t terminal_width,
							struct s_term_pos start, size_t width)
{
	size_t				i;
	struct s_term_pos	pos;

	i = 0;
	pos = start;
	while (i < width)
	{
		i++;
		pos.column++;
		if (pos.column == terminal_width)
		{
			pos.column = 0;
			pos.row++;
		}
	}
	if (pos.column == 0 && i > 0)
	{
		pos.row--;
		pos.column = terminal_width;
	}
	return (pos);
}
