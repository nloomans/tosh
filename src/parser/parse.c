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

#include "private.h"

t_error		parser_parse(
				struct s_complete_command **const complete_command,
				bool *const extra_input_requested,
				t_list_meta *const all_token)
{
	t_parser p;

	ft_memset(&p, '\0', sizeof(p));
	p.all_token = *all_token;
	p.cursor = p.all_token.first;
	*complete_command = parse_complete_command(&p);
	*extra_input_requested = p.extra_input_requested;
	if (p.extra_input_requested || is_error(p.error))
	{
		free_complete_command(*complete_command);
		*complete_command = NULL;
	}
	if (*extra_input_requested)
	{
		return (error_none());
	}
	return (p.error);
}

void	parser_del(struct s_complete_command **const complete_command)
{
	free_complete_command(*complete_command);
	*complete_command = NULL;
}
