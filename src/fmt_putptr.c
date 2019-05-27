/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putptr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 19:33:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/28 00:09:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "writer.h"
#include "token.h"
#include <stdarg.h>

void			fmt_putptr(t_writer *writer, t_token *token, va_list vlist)
{
	void			*ptr;

	(void)token;
	writer_write(writer, "0x", 2);
	ptr = va_arg(vlist, void*);
	(void)ptr;
}
