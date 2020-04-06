/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: aholster <aholster@student.codam.nl>          +:+                    */
/*       ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*       nloomans <nloomans@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
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
