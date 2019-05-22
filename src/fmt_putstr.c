/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:33:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/23 01:20:48 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include <libft.h>

ssize_t			fmt_putpercent(t_writer *writer, t_token *token, va_list vlist)
{
	(void)vlist;
	(void)token;
	return (writer_write(writer, "%", 1));
}

ssize_t			intern_fmt_pad(t_writer *writer, char c, size_t amt)
{
	size_t i;

	i = 0;
	while (i < amt)
	{
		writer_write(writer, &c, 1);
		i++;
	}
	return (i);
}

ssize_t			fmt_putstr(t_writer *writer, t_token *token, va_list vlist)
{
	char	*str;
	size_t	len;
	size_t	write_amt;

	str = va_arg(vlist, char*);
	if (str == NULL)
	{
		return (writer_write(writer, "(null)", 6));
	}
	else
	{
		len = ft_strlen(str);
		write_amt = ft_min(len, (token->flags & FLAGS_PRECISION) ?
			(size_t)token->precision : len);
		return (intern_fmt_pad(writer, ' ', token->width - write_amt)
			+ writer_write(writer, str, write_amt));
	}
}

ssize_t			fmt_putstrlit(t_writer *writer, t_token *token, va_list vlist)
{
	(void)vlist;
	return (writer_write(writer, token->s_value,
		token->s_length));
}

ssize_t			fmt_putchr(t_writer *writer, t_token *token, va_list vlist)
{
	char c;

	(void)token;
	c = (char)va_arg(vlist, int);
	return (writer_write(writer, &c, 1));
}
