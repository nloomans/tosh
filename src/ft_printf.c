/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:35:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/20 15:49:23 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>

#include "writer.h"

ssize_t	ft_vwprintf(t_writer *writer, char *fmt, va_list vlist)
{
	(void)vlist;
	return (writer_write(writer, fmt, ft_strlen(fmt)));
}

ssize_t	ft_vprintf(char *fmt, va_list vlist)
{
	t_writer_fd_state	fd;
	t_writer			writer;

	fd = 1;
	writer.state = (void*)&fd;
	writer.write = &writer_fd_write;
	return (ft_vwprintf(&writer, fmt, vlist));
}

ssize_t	ft_vaprintf(char **dest, char *fmt, va_list vlist)
{
	t_writer_alloc_state	st;
	t_writer				writer;

	st.len = 0;
	st.str_ptr = dest;
	writer.state = (void*)&st;
	writer.write = &writer_alloc_write;
	return (ft_vwprintf(&writer, fmt, vlist));
}

ssize_t	ft_aprintf(char **dest, char *fmt, ...)
{
	va_list	vlist;
	ssize_t	ret;

	va_start(vlist, fmt);
	ret = ft_vaprintf(dest, fmt, vlist);
	va_end(vlist);
	return (ret);
}

ssize_t	ft_printf(char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vprintf(fmt, vlist);
	va_end(vlist);
	return (ret);
}
