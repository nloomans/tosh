/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_checkers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 18:57:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/26 18:57:46 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stddef.h>
#include <libft.h>
#include "token.h"
#include "parser.h"

int			is_conversion_specification(const char *stream)
{
	assert(stream != NULL);
	return (*stream == '%');
}

int			is_color_specification(const char *stream)
{
	assert(stream != NULL);
	return (stream[0] == '%' && stream[1] == '{');
}
