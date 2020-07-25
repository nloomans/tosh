/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 15:45:38 by nmartins      #+#    #+#                 */
/*   Updated: 2019/07/08 16:38:02 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"
#include <stdarg.h>
#include "ft_printf.h"
#include "writer.h"

ssize_t		ft_vdprintf(int fd, char *fmt, va_list vlist)
{
	t_writer_fd_state	st;
	t_writer			writer;

	st = fd;
	std_memset(&writer, 0, sizeof(t_writer));
	writer.state = (void*)&st;
	writer.write = &writer_fd_write;
	return (ft_vwprintf(&writer, fmt, vlist));
}

ssize_t		ft_dprintf(int fd, char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vdprintf(fd, fmt, vlist);
	va_end(vlist);
	return (ret);
}

/*
** This function will print the format string to stderr and then return the
** first argument.
**
** Example:
**     if (err == -1)
**         return (ft_eprintf(-1, "xyz went wrong\n"));
*/

int			ft_eprintf(int exit_code, char *fmt, ...)
{
	va_list		vlist;

	va_start(vlist, fmt);
	(void)ft_vdprintf(2, fmt, vlist);
	va_end(vlist);
	return (exit_code);
}
