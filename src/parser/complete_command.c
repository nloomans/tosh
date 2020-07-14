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

#include <assert.h>
#include <stdlib.h>
#include "private.h"

static void					check_unexpected_token(t_parser *const p)
{
	struct s_token *unexpected;

	unexpected = parser__peek_token(p);
	if (!unexpected)
		return ;
	if (unexpected->type == WORD)
		parser__errorf(p, "unexpected word '%s'", unexpected->string);
	else if (unexpected->type == OPERATOR)
		parser__errorf(p, "unexpected operator '%s'", unexpected->string);
	else if (unexpected->type == IO_NUMBER)
		parser__errorf(p, "unexpected io_number '%s'", unexpected->string);
	else
		assert(0);
}

struct s_complete_command	*parse_complete_command(t_parser *const p)
{
	struct s_complete_command *complete_command;

	complete_command = ft_memalloc(sizeof(*complete_command));
	complete_command->list = parse_list(p);
	check_unexpected_token(p);
	if (!complete_command->list)
	{
		free_complete_command(complete_command);
		return (NULL);
	}
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
