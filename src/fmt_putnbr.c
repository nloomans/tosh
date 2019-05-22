/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putnbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:52:31 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/23 00:56:32 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "writer.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>

ssize_t			fmt_putnbr(t_writer *writer, t_token *token, va_list vlist)
{
	char	*str;

	(void)token;
	// TODO: lots.
	str = ft_itoa(va_arg(vlist, int));
	// printf(">>%s<<\n", str);
	return (writer_write(writer, str, ft_strlen(str)));
}
