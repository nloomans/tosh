/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:33:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/28 01:02:19 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
# include <stdio.h>
#include <libft.h>

void			fmt_putstr(t_writer *writer, t_token *token, va_list vlist)
{
	char	*str;
	size_t	len;
	size_t	trimmed_length;
	char	do_print;

	intern_pop_wildcards(token, vlist);
	str = va_arg(vlist, char *);
	if (str == NULL)
	{
		do_print = (token->precision < 0 || token->precision >= 6) ? 6 : 0;
		intern_fmt_pad_left(writer, token, ' ', do_print);
		if (do_print)
			writer_write(writer, "(null)", 6);
		intern_fmt_pad_right(writer, token, ' ', do_print);
	}
	else
	{
		len = ft_strlen(str);
		if (token->precision < 0)
			token->flags &= ~FLAGS_PRECISION;
		trimmed_length = token->flags & FLAGS_PRECISION
			? (size_t)ft_min(len, token->precision)
			: len;
		intern_fmt_pad_left(writer, token, ' ', trimmed_length);
		writer_write(writer, str, trimmed_length);
		intern_fmt_pad_right(writer, token, ' ', trimmed_length);
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
