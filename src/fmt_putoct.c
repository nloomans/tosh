/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putoct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 20:43:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/26 23:02:40 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "writer.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>

void			intern_fmt_putoct(t_writer *writer, unsigned value)
{
	char	c;

	if (value > 8)
		intern_fmt_putoct(writer, value / 8);
	c = '0' + (value % 8);
	writer_write(writer, &c, 1);
}

void			fmt_putoct(t_writer *writer, t_token *token, va_list vlist)
{
	unsigned int	n;

	n = va_arg(vlist, unsigned int);
	if (token->flags & FLAGS_HASH && n != 0)
		writer_write(writer, "0", 1);
	intern_fmt_putoct(writer, n);
}
