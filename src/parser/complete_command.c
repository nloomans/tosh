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

struct s_complete_command	*parse_complete_command(t_parser *const p)
{
	struct s_complete_command *complete_command;

	complete_command = ft_memalloc(sizeof(*complete_command));
	complete_command->list = parse_list(p);
	if (!complete_command->list)
	{
		free_complete_command(complete_command);
		return (NULL);
	}
	parser__next_if_token(p, OPERATOR, ";");
	return (complete_command);
}

void						free_complete_command(
								struct s_complete_command
									*const complete_command)
{
	if (complete_command)
	{
		free_list(complete_command->list);
		free(complete_command);
	}
}
