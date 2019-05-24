/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:33:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/24 17:02:48 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
# include <stdio.h>
#include <libft.h>

void			fmt_putstr(t_writer *writer, t_token *token, va_list vlist)
{
	char	*str;
	size_t	len;
	size_t	write_amt;

	intern_pop_wildcards(token, vlist);
	str = va_arg(vlist, char*);
	if (str == NULL)
		writer_write(writer, "(null)", 6);
	else
	{
		len = ft_strlen(str);
		write_amt = ft_min(len, (token->flags & FLAGS_PRECISION) ?
			(size_t)token->precision : len);
		intern_fmt_pad(writer, ' ', (ft_max(len, token->width)) - write_amt);
		writer_write(writer, str, write_amt);
	}
}

void			fmt_putstrlit(t_writer *writer, t_token *token, va_list vlist)
{
	(void)vlist;
	writer_write(writer, token->s_value, token->s_length);
}

void			fmt_putchr(t_writer *writer, t_token *token, va_list vlist)
{
	char		c;

	c = (char)va_arg(vlist, int);
	if ((token->flags & FLAGS_LEFTALIGN) == 0)
		intern_fmt_pad(writer, ' ', ft_max(0, token->width - 1));
	writer_write(writer, &c, 1);
	if (token->flags & FLAGS_LEFTALIGN)
		intern_fmt_pad(writer, ' ', ft_max(0, token->width - 1));
}
