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

#include <unistd.h>
#include "history.h"

void			history_destroy(t_history **history)
{
	struct s_history_node	*node;

	close((*history)->fd);
	while ((*history)->history.len > 0)
	{
		node = unpack_history_node((*history)->history.first);
		ft_list_unlink(&(*history)->history, (*history)->history.first);
		ft_strdel(&node->buffer);
		ft_memdel((void **)&node);
	}
	ft_memdel((void **)history);
}
