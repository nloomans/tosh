/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:33:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/22 20:19:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include <libft.h>

int				fmt_putpercent(t_writer *writer, t_token *token, va_list vlist)
{
	(void)vlist;
	(void)token;
	return (writer_write(writer, "%", 1));
}

int				fmt_putstr(t_writer *writer, t_token *token, va_list vlist)
{
	char *str;

	(void)token;
	str = va_arg(vlist, char*);
	if (str == NULL)
	{
		return (writer_write(writer, "(null)", 6));
	}
	else
	{
		return (writer_write(writer, str, ft_strlen(str)));
	}
}

int				fmt_putstrlit(t_writer *writer, t_token *token, va_list vlist)
{
	(void)vlist;
	return (writer_write(writer, token->value.as_literal.value,
		token->value.as_literal.length));
}

int				fmt_putchr(t_writer *writer, t_token *token, va_list vlist)
{
	char c;

	(void)token;
	c = (char)va_arg(vlist, int);
	return (writer_write(writer, &c, 1));
}
