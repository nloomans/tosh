/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:35:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/24 17:04:10 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>

#include "writer.h"
#include "token.h"

ssize_t		ft_vwprintf(t_writer *writer, char *fmt, va_list vlist)
{
	int			res;
	t_token		token;

	while (1)
	{
		res = parse_token(&token, &fmt);
		if (res < 0)
			return (res);
		run_token(writer, vlist, &token);
		if (writer->failed)
			return (-1);
		if (*fmt == '\0')
			return (writer->written);
	}
	return (writer->written);
}

ssize_t		ft_vfprintf(int fd, char *fmt, va_list vlist)
{
	t_writer_fd_state	st;
	t_writer			writer;

	st = fd;
	ft_memset(&writer, 0, sizeof(t_writer));
	writer.state = (void*)&st;
	writer.write = &writer_fd_write;
	return (ft_vwprintf(&writer, fmt, vlist));
}

ssize_t		ft_vaprintf(char **dest, char *fmt, va_list vlist)
{
	t_writer_alloc_state	st;
	t_writer				writer;

	*dest = NULL;
	st.len = 0;
	st.str_ptr = dest;
	ft_memset(&writer, 0, sizeof(t_writer));
	writer.state = (void*)&st;
	writer.write = &writer_alloc_write;
	return (ft_vwprintf(&writer, fmt, vlist));
}

ssize_t		ft_aprintf(char **dest, char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vaprintf(dest, fmt, vlist);
	va_end(vlist);
	return (ret);
}

ssize_t		ft_printf(char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vfprintf(1, fmt, vlist);
	va_end(vlist);
	return (ret);
}

ssize_t		ft_fprintf(int fd, char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vfprintf(fd, fmt, vlist);
	va_end(vlist);
	return (ret);
}
