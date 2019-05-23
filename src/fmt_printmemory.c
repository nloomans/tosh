/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_printmemory.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:39:30 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/23 18:12:47 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

#include <libft.h>
# include <stdio.h>


static ssize_t	intern_fmt_puthexchar(
	t_writer *writer,
	unsigned char c,
	t_flags flags)
{
	const char b = intern_to_hex(c % 16, flags & FLAGS_CAPITAL);
	const char a = intern_to_hex(c / 16, flags & FLAGS_CAPITAL);

	return (
		writer_write(writer, (char*)&a, 1) +
		writer_write(writer, (char*)&b, 1));
}

static ssize_t	intern_fmt_putmemchars(
	t_writer *writer,
	unsigned char *bytes,
	size_t offset,
	size_t len)
{
	const size_t	start = offset;
	size_t			written;

	written = 0;
	while (offset < len && offset - start < 16)
	{
		if (ft_isprint(bytes[offset]))
			written += writer_write(writer, (char*)&bytes[offset], 1);
		else
			written += writer_write(writer, ".", 1);
		offset++;
	}
	return (written);
}

ssize_t			intern_fmt_printmemory(
	t_writer *writer,
	unsigned char *bytes,
	size_t len,
	t_flags flags)
{
	size_t			row;
	size_t			column;
	ssize_t			written;

	written = 0;
	row = 0;
	while (row < ((len - 1) / 16) + 1)
	{
		column = 0;
		while (column < 16)
		{
			if (column > 0 && column % 2 == 0)
				written += writer_write(writer, " ", 1);
			if (column + (row * 16) < len)
				written += intern_fmt_puthexchar(writer,
					bytes[column + (row * 16)], flags);
			else
				written += writer_write(writer, "  ", 2);
			column++;
		}
		written += writer_write(writer, " ", 1) + intern_fmt_putmemchars(
			writer, bytes, row * 16, len) + writer_write(writer, "\n", 1);
		row++;
	}
	return (written);
}

ssize_t			fmt_printmemory(t_writer *writer, t_token *token, va_list vlist)
{
	void	*addr;
	size_t	len;

	(void)token;
	addr = va_arg(vlist, void*);
	len = va_arg(vlist, size_t);
	return (intern_fmt_printmemory(writer,
		(unsigned char *)addr, len, token->flags));
}
