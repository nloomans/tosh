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

#include "history.h"

t_error						history_push(struct s_history *history,
								const char *new_buffer)
{
	struct s_history_node *node;

	node = ft_memalloc(sizeof(*node));
	if (node == NULL)
		return (errorf("out of memory"));
	node->buffer = ft_strdup(new_buffer);
	if (node->buffer == NULL)
	{
		ft_memdel((void **)&node);
		return (errorf("out of memory"));
	}
	ft_list_insert(&history->history, history->history.last, &node->conn);
	history->cursor = NULL;
	if (ft_dprintf(history->fd, "%s\n", new_buffer) == -1)
		return (errorf("failed to write to history file"));
	return (error_none());
}
