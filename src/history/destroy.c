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

#include "private.h"

void			history_destroy(t_history **history)
{
	struct s_history__line	*line;

	close((*history)->fd);
	while ((*history)->lines.len > 0)
	{
		line = unpack_line((*history)->lines.first);
		ft_list_unlink(&(*history)->lines, (*history)->lines.first);
		ft_strdel(&line->buffer);
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)history);
}
