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

#include <libft.h>
#include <ft_printf.h>

#include "private.h"

t_error						history_push(struct s_history *history,
								const char *new_buffer)
{
	struct s_history__line	*line;

	line = ft_memalloc(sizeof(*line));
	if (line == NULL)
		return (errorf("out of memory"));
	line->buffer = ft_strdup(new_buffer);
	if (line->buffer == NULL)
	{
		ft_memdel((void **)&line);
		return (errorf("out of memory"));
	}
	ft_list_insert(&history->lines, history->lines.last, &line->conn);
	history->cursor = NULL;
	if (ft_dprintf(history->fd, "%s\n", new_buffer) == -1)
		return (errorf("failed to write to history file"));
	return (error_none());
}
