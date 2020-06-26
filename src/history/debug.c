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

#include <stdlib.h>
#include <ft_printf.h>

#include "history.h"

static void		print_history(const t_list_meta *history)
{
	const struct s_history_node	*node;

	node = unpack_history_node(history->first);
	while (node != NULL)
	{
		ft_printf("buffer |%s|\n", node->buffer);
		node = unpack_history_node(node->conn.next);
	}
}

int				history_debug(void)
{
	t_error		error;
	t_history	*history;
	char		*path;

	if (ft_asprintf(&path, "%s/.tosh_history", getenv("HOME")) == -1)
		return (ft_eprintf(1, "tosh: out of memory\n"));
	error = history_create(&history, path);
	ft_strdel(&path);
	if (is_error(error))
		return (ft_eprintf(1, "tosh: %s\n", error.msg));
	print_history(&history->history);
	history_destroy(&history);
	return (0);
}
