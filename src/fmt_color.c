/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 01:24:49 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/26 00:37:59 by nmartins      ########   odam.nl         */
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
		COLOR_WHITE,
		COLOR_UNDERLINE,
		COLOR_REVERSED,
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

void		fmt_putcolor(t_writer *writer, t_token *token, va_list vlist)
{
	const char	*lookup[] = {
		"reset",
		"black",
		"gray",
		"red",
		"green",
		"yellow",
		"blue",
		"magenta",
		"cyan",
		"white",
		"underline",
		"reversed"
	};
	size_t		i;

	i = 0;
	(void)vlist;	
	while (i < sizeof(lookup) / sizeof(char*))
	{
		if (!ft_memcmp(lookup[i], token->s_value, ft_strlen(lookup[i])))
		{
			intern_fmt_color(writer, (t_color)i);
		}
		i++;
	}
}
