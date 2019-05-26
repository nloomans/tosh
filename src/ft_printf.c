/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:35:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/26 23:23:53 by nmartins      ########   odam.nl         */
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

ssize_t		ft_vasprintf(char **dest, char *fmt, va_list vlist)
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

ssize_t		ft_asprintf(char **dest, char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vasprintf(dest, fmt, vlist);
	va_end(vlist);
	return (ret);
}


ssize_t		ft_vsnprintf(char *dest, ssize_t capacity, char *fmt, va_list vlist)
{
	t_writer_string_state	st;
	t_writer				writer;

	st.maximum = capacity;
	st.str_ptr = dest;
	/* potentially harmful / useless (?) */
	if (capacity > 0)
		ft_memset(st.str_ptr, 0, capacity);
	/* need reviewing ^^^ */
	ft_memset(&writer, 0, sizeof(t_writer));
	writer.state = (void*)&st;
	writer.write  = &writer_string_write;
	return (ft_vwprintf(&writer, fmt, vlist));
}

ssize_t		ft_snprintf(char *dest, ssize_t capacity, char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vsnprintf(dest, capacity, fmt, vlist);
	va_end(vlist);
	return (ret);
}

ssize_t		ft_sprintf(char *dest, char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vsnprintf(dest, -1, fmt, vlist);
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
