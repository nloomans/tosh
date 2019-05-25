/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_padding.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 17:27:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/26 01:02:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "token.h"
#include <libft.h>
#include <stdlib.h>

void	intern_fmt_pad(t_writer *writer, char c, size_t amt)
{
	char	*str;

	str = (char*)malloc(amt);
	if (!str)
		return ;
	ft_memset(str, c, amt);
	writer_write(writer, str, amt);
	ft_strdel(&str);
}

void	intern_fmt_pad_auto(
	t_writer *writer,
	char c,
	size_t pad_amount,
	size_t length)
{
	if (pad_amount > length)
		intern_fmt_pad(writer, c, pad_amount - length);
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
