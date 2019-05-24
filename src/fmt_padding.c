/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_padding.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 17:27:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/24 17:30:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "token.h"

void	intern_fmt_pad(t_writer *writer, char c, size_t amt)
{
	size_t i;

	i = 0;
	while (i < amt)
	{
		writer_write(writer, &c, 1);
		i++;
	}
}

void	intern_fmt_pad_auto(
	t_writer *writer,
	char c,
	size_t pad_amount,
	size_t length)
{
	size_t	i;

	i = 0;
	if (pad_amount > length)
	{
		while (i < (pad_amount - length))
		{
			writer_write(writer, &c, 1);
			i++;
		}
	}
}

void	intern_fmt_pad_left(
	t_writer *writer,
	t_token *token,
	char c,
	size_t length)
{
	if ((token->flags & FLAGS_LEFTALIGN) == 0)
		intern_fmt_pad_auto(writer, c, token->width, length);
}

void	intern_fmt_pad_right(
	t_writer *writer,
	t_token *token,
	char c,
	size_t length)
{
	if (token->flags & FLAGS_LEFTALIGN)
		intern_fmt_pad_auto(writer, c, token->width, length);
}
