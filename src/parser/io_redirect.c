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

/*
** TODO: remove ft_printf
*/
#include <assert.h>
#include <ft_printf.h>
#include "private.h"

static int				parse_io_number(t_parser *p)
{
	char	*num_str;

	if (!parser__is_token(p, IO_NUMBER, NULL))
		return (1);
	num_str = parser__next_token(p)->string;
	return (ft_atoi(num_str));
}

struct s_io_redirect	*parse_io_redirect(t_parser *p)
{
	struct s_io_redirect	*io_redirect;

	io_redirect = ft_memalloc(sizeof(*io_redirect));
	io_redirect->fd = parse_io_number(p);
	if (parser__next_if_token(p, OPERATOR, "<"))
		io_redirect->type = REDIRECT_IN;
	else if (parser__next_if_token(p, OPERATOR, ">"))
		io_redirect->type = REDIRECT_OUT;
	else if (parser__next_if_token(p, OPERATOR, ">>"))
		io_redirect->type = REDIRECT_OUT_APPEND;
	else
	{
		del_io_redirect(&io_redirect);
		return (NULL);
	}
	if (!parser__is_token(p, WORD, NULL))
	{
		parser__errorf(p, "no filename after redirect");
		del_io_redirect(&io_redirect);
		return (NULL);
	}
	io_redirect->file = ft_strdup(parser__next_token(p)->string);
	return (io_redirect);
}

void					del_io_redirect(
							struct s_io_redirect **const io_redirect)
{
	ft_strdel(&(*io_redirect)->file);
	ft_memdel((void **)io_redirect);
}
