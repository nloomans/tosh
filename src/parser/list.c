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
#include "private.h"

struct s_list	*parse_list(t_parser *const p)
{
	struct s_list *list;

	list = ft_memalloc(sizeof(*list));
	list->pipe_sequence = parse_pipe_sequence(p);
	if (!list->pipe_sequence)
	{
		free_list(list);
		return (NULL);
	}
	parser__next_if_token(p, OPERATOR, ";");
	list->list = parse_list(p);
	return (list);
}

void			free_list(struct s_list *const list)
{
	if (list)
	{
		free_pipe_sequence(list->pipe_sequence);
		free_list(list->list);
		free(list);
	}
}
