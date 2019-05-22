/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putptr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 19:33:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/23 00:47:49 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "writer.h"
#include "token.h"
#include <stdarg.h>

ssize_t			fmt_putptr(t_writer *writer, t_token *token, va_list vlist)
{
	void			*ptr;
	size_t			written;
	unsigned long	addr;

	(void)token;
	written = writer_write(writer, "0x", 2);
	ptr = va_arg(vlist, void*);
	addr = (unsigned long)ptr;
	intern_fmt_puthex(writer, addr, 0);
	return (written);
}
