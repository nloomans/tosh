/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_printmemory.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:39:30 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/24 16:55:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

#include <libft.h>
# include <stdio.h>

static void	intern_fmt_puthexchar(
	t_writer *writer,
	unsigned char c,
	t_flags flags)
{
	const char b = intern_to_hex(c % 16, flags & FLAGS_CAPITAL);
	const char a = intern_to_hex(c / 16, flags & FLAGS_CAPITAL);

	writer_write(writer, (char*)&a, 1);
	writer_write(writer, (char*)&b, 1);
}

static void	intern_fmt_putmemchars(
	t_writer *writer,
	unsigned char *bytes,
	size_t offset,
	size_t len)
{
	const size_t	start = offset;

	while (offset < len && offset - start < 16)
	{
		if (ft_isprint(bytes[offset]))
			writer_write(writer, (char*)&bytes[offset], 1);
		else
			writer_write(writer, ".", 1);
		offset++;
	}
}

void			intern_fmt_printmemory(
	t_writer *writer,
	unsigned char *bytes,
	size_t len,
	t_flags flags)
{
	size_t			row;
	size_t			column;

	row = 0;
	while (row < ((len - 1) / 16) + 1)
	{
		column = 0;
		while (column < 16)
		{
			if (column > 0 && column % 2 == 0)
				writer_write(writer, " ", 1);
			if (column + (row * 16) < len)
				intern_fmt_puthexchar(writer,
					bytes[column + (row * 16)], flags);
			else
				writer_write(writer, "  ", 2);
			column++;
		}
		writer_write(writer, " ", 1);
		intern_fmt_putmemchars(writer, bytes, row * 16, len);
		writer_write(writer, "\n", 1);
		row++;
	}
}

void			fmt_printmemory(t_writer *writer, t_token *token, va_list vlist)
{
	void	*addr;
	size_t	len;

	addr = va_arg(vlist, void*);
	len = va_arg(vlist, size_t);
	intern_fmt_printmemory(writer, (unsigned char *)addr, len, token->flags);
}
