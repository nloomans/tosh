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

static struct s_io_file	*identify_redirection_type(t_parser *const p)
{
	struct s_io_file		*io_file;

	io_file = ft_memalloc(sizeof(*io_file));
	if (parser__next_if_token(p, OPERATOR, "<&"))
		io_file->type = REDIRECT_IN_AND;
	else if (parser__next_if_token(p, OPERATOR, "<"))
		io_file->type = REDIRECT_IN;
	else if (parser__next_if_token(p, OPERATOR, ">"))
		io_file->type = REDIRECT_OUT;
	else if (parser__next_if_token(p, OPERATOR, ">>"))
		io_file->type = REDIRECT_OUT_APPEND;
	else if (parser__next_if_token(p, OPERATOR, ">&"))
		io_file->type = REDIRECT_OUT_AND;
	else
	{
		free_io_file(io_file);
		return (NULL);
	}
	return (io_file);
}

struct s_io_file		*parse_io_file(t_parser *const p)
{
	struct s_io_file	*io_file;

	io_file = identify_redirection_type(p);
	if (io_file == NULL)
	{
		return (NULL);
	}
	if (!parser__is_token(p, WORD, NULL))
	{
		parser__errorf(p, "no filename after redirect");
		free_io_file(io_file);
		return (NULL);
	}
	io_file->filename = ft_strdup(parser__next_token(p)->string);
	return (io_file);
}

void					free_io_file(
							struct s_io_file *const io_file)
{
	if (io_file)
	{
		free(io_file->filename);
		free(io_file);
	}
}
