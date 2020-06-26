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

#include <stddef.h>
#include "history.h"

char	*history_up(struct s_history *history)
{
	if (history->cursor == NULL)
	{
		if (history->history.last == NULL)
			return (NULL);
		history->cursor = history->history.last;
	}
	else
	{
		if (history->cursor->prev == NULL)
			return (NULL);
		history->cursor = history->cursor->prev;
	}
	return (unpack_history_node(history->cursor)->buffer);
}
