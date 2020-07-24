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

static struct s_io_here		*fill_io_here(struct s_io_here *const io_here,
								t_parser *const p)
{
	if (!parser__next_if_token(p, OPERATOR, "<<"))
	{
		return (NULL);
	}
	if (!parser__is_token(p, WORD, NULL))
	{
		parser__errorf(p, "incomplete heredoc");
		return (NULL);
	}
	io_here->here_end = ft_strdup(parser__next_token(p)->string);
	if (io_here->here_end)
	{
		parser__errorf(p, "unable to allocate memory");
		return (NULL);
	}
	return (io_here);
}

struct s_io_here			*parse_io_here(t_parser *const p)
{
	struct s_io_here		*io_here;

	io_here = ft_memalloc(sizeof(*io_here));
	if (io_here == NULL)
	{
		parser__errorf(p, "unable to allocate memory");
		return (NULL);
	}
	if (fill_io_here(io_here, p) == NULL || is_error(p->error))
	{
		free_io_here(io_here);
		return (NULL);
	}
	return (io_here);
}

void						free_io_here(struct s_io_here *const io_here)
{
	if (io_here)
	{
		free(io_here->here_end);
		free(io_here);
	}
}
