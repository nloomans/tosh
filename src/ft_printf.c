/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:35:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/22 16:30:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>

#include "writer.h"
#include "token.h"

# include <stdio.h>

ssize_t		ft_vwprintf(t_writer *writer, char *fmt, va_list vlist)
{
	int			res;
	ssize_t		count;
	t_token		token;

	printf("printf called with >> %s <<\n", fmt);
	count = 0;
	while (1)
	{
		// printf("fmt at this time '%s'; \n", fmt);
		res = parse_token(&token, &fmt);
		if (res < 0)
			return (res);
		res = run_token(writer, vlist, &token);
		if (res < 0)
			return (res);
		if (*fmt == '\0')
			return (count);
	}
	return (count);
}

ssize_t		ft_vprintf(char *fmt, va_list vlist)
{
	t_writer_fd_state	fd;
	t_writer			writer;

	fd = 1;
	writer.state = (void*)&fd;
	writer.write = &writer_fd_write;
	return (ft_vwprintf(&writer, fmt, vlist));
}

ssize_t		ft_vaprintf(char **dest, char *fmt, va_list vlist)
{
	t_writer_alloc_state	st;
	t_writer				writer;

	st.len = 0;
	st.str_ptr = dest;
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
	ret = ft_vprintf(fmt, vlist);
	va_end(vlist);
	return (ret);
}
