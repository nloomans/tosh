/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:33:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/23 19:59:08 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
# include <stdio.h>
#include <libft.h>

ssize_t			fmt_putpercent(t_writer *writer, t_token *token, va_list vlist)
{
	ssize_t		written;

	(void)vlist;
	written = 0;
	if ((token->flags & FLAGS_LEFTALIGN) == 0)
		written += intern_fmt_pad(writer, ' ', ft_max(0, token->width - 1));
	written += writer_write(writer, "%", 1);
	if (token->flags & FLAGS_LEFTALIGN)
		written += intern_fmt_pad(writer, ' ', ft_max(0, token->width - 1));
	return (written);
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
		return (intern_fmt_pad(writer, ' ',
			(ft_max(len, token->width)) - write_amt)
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
	char		c;
	ssize_t		written;

	written = 0;
	c = (char)va_arg(vlist, int);
	if ((token->flags & FLAGS_LEFTALIGN) == 0)
		written += intern_fmt_pad(writer, ' ', ft_max(0, token->width - 1));
	written += writer_write(writer, &c, 1);
	if (token->flags & FLAGS_LEFTALIGN)
		written += intern_fmt_pad(writer, ' ', ft_max(0, token->width - 1));
	return (written);
}
