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
