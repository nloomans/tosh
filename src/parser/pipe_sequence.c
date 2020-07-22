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

static void				parse_linebreak(t_parser *const p)
{
	while (parser__next_if_token(p, OPERATOR, "\n"))
	{
	}
}

struct s_pipe_sequence	*parse_pipe_sequence(t_parser *const p)
{
	struct s_pipe_sequence *pipe_sequence;

	pipe_sequence = ft_memalloc(sizeof(*pipe_sequence));
	if (pipe_sequence == NULL)
	{
		parser__errorf(p, "unable to allocate memory");
		return (NULL);
	}
	pipe_sequence->simple_command = parse_simple_command(p);
	if (is_error(p->error) || !pipe_sequence->simple_command)
	{
		free_pipe_sequence(pipe_sequence);
		return (NULL);
	}
	if (parser__next_if_token(p, OPERATOR, "|"))
	{
		parse_linebreak(p);
		pipe_sequence->pipe_sequence = parse_pipe_sequence(p);
		if (is_error(p->error) || !pipe_sequence->pipe_sequence)
		{
			parser__errorf(p, "incomplete pipe");
			free_pipe_sequence(pipe_sequence);
			return (NULL);
		}
	}
	return (pipe_sequence);
}

void					free_pipe_sequence(
							struct s_pipe_sequence *const pipe_sequence)
{
	if (pipe_sequence)
	{
		free_pipe_sequence(pipe_sequence->pipe_sequence);
		free_simple_command(pipe_sequence->simple_command);
		free(pipe_sequence);
	}
}
