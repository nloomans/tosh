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

static char				*parse_name(t_parser *const p)
{
	if (parser__is_token(p, WORD, NULL))
	{
		return (ft_strdup(parser__next_token(p)->string));
	}
	return (NULL);
}

struct s_simple_command *parse_simple_command(t_parser *const p)
{
	struct s_simple_command *simple_command;

	simple_command = ft_memalloc(sizeof(*simple_command));
	simple_command->prefix = parse_cmd_prefix(p);
	simple_command->name = parse_name(p);
	if (simple_command->name)
	{
		simple_command->suffix = parse_cmd_suffix(p);
	}
	if (!simple_command->prefix && !simple_command->name)
	{
		free_simple_command(simple_command);
		return (NULL);
	}
	return (simple_command);
}

void                    free_simple_command(
	                        struct s_simple_command *const simple_command)
{
	if (simple_command)
	{
		free_cmd_prefix(simple_command->prefix);
		free_cmd_suffix(simple_command->suffix);
		free(simple_command->name);
		free(simple_command);
	}
}
