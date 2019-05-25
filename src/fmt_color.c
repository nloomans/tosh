/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 01:24:49 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/25 01:47:54 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "color.h"
#include <libft.h>

const char	*intern_fmt_color_lookup(t_color color)
{
	const char	*lookup[] = {
		COLOR_RESET,
		COLOR_BLACK,
		COLOR_GRAY,
		COLOR_RED,
		COLOR_GREEN,
		COLOR_YELLOW,
		COLOR_BLUE,
		COLOR_MAGENTA,
		COLOR_CYAN,
		COLOR_WHITE
	};

	return (lookup[color]);
}

void		intern_fmt_color(t_writer *writer, t_color color)
{
	const char *str = intern_fmt_color_lookup(color);
	writer_write(
		writer,
		(char *)str,
		ft_strlen(str));
}
