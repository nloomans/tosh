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

#include "private.h"

static void		print_history(const t_list_meta *history)
{
	const struct s_history__line	*node;

	node = unpack_line(history->first);
	while (node != NULL)
	{
		ft_printf("buffer |%s|\n", node->buffer);
		node = unpack_line(node->conn.next);
	}
}

int				history_debug(void)
{
	t_error		error;
	t_history	*history;

	error = history_create(&history);
	if (is_error(error))
		return (ft_eprintf(1, "tosh: %s\n", error.msg));
	print_history(&history->lines);
	history_destroy(&history);
	return (0);
}
