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

static int				parse_io_number(t_parser *const p)
{
	char	*num_str;

	if (!parser__is_token(p, IO_NUMBER, NULL))
		return (-1);
	num_str = parser__next_token(p)->string;
	return (ft_atoi(num_str));
}

struct s_io_redirect	*parse_io_redirect(t_parser *const p)
{
	struct s_io_redirect	*io_redirect;

	io_redirect = ft_memalloc(sizeof(*io_redirect));
	io_redirect->fd = parse_io_number(p);
	io_redirect->file = parse_io_file(p);
	if (!io_redirect->file)
	{
		io_redirect->here = parse_io_here(p);
	}
	if (!io_redirect->file && !io_redirect->here)
	{
		free_io_redirect(io_redirect);
		return (NULL);
	}
	return (io_redirect);
}

void					free_io_redirect(
							struct s_io_redirect *const io_redirect)
{
	if (io_redirect)
	{
		free_io_file(io_redirect->file);
		free_io_here(io_redirect->here);
		free(io_redirect);
	}
}
