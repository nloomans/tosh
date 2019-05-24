/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:31:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/24 13:38:07 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"


// TODO: add auto-padding detector
ssize_t			intern_fmt_pad(t_writer *writer, char c, size_t amt)
{
	size_t i;

	i = 0;
	while (i < amt)
	{
		writer_write(writer, &c, 1);
		i++;
	}
	return (i);
}
