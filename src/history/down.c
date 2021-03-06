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

#include "private.h"

char	*history_down(struct s_history *history)
{
	if (history->cursor == NULL)
		return (NULL);
	history->cursor = history->cursor->next;
	if (history->cursor == NULL)
		return (ft_strdup(""));
	return (ft_strdup(unpack_line(history->cursor)->buffer));
}
