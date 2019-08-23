/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_memory.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 18:39:56 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/30 18:52:21 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_hex_half(unsigned char byte)
{
	if (byte <= 9)
		ft_putchar(byte + '0');
	else
		ft_putchar(byte - 10 + 'a');
}

static void		print_hex(unsigned char byte)
{
	unsigned char first;
	unsigned char last;

	first = byte / 16;
	last = byte % 16;
	print_hex_half(first);
	print_hex_half(last);
}

static void		print_human(const unsigned char *data, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (data[i] >= ' ' && data[i] <= '~')
			ft_putchar(data[i]);
		else
			ft_putchar('.');
		i++;
	}
}

static void		print_times(char c, size_t count)
{
	while (count > 0)
	{
		ft_putchar(c);
		count--;
	}
}

void			ft_print_memory(const void *addr, size_t size)
{
	unsigned char	*data;
	size_t			i;
	size_t			start_line;
	size_t			line_length;
	size_t			line_size;

	data = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_hex(data[i]);
		i++;
		if (i % 2 == 0)
			ft_putchar(' ');
		if (i % 16 == 0 || i == size)
		{
			line_length = i % 16 == 0 ? 16 : i % 16;
			line_size = line_length * 2.5;
			start_line = i - line_length;
			print_times(' ', 40 - line_size);
			print_human(data + start_line, line_length);
			ft_putchar('\n');
		}
	}
}
