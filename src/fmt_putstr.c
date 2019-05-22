/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:33:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/22 16:44:25 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

int				fmt_putstr(t_writer *writer, t_token *token, va_list vlist)
{
	(void)token;
	(void)writer;
	(void)vlist;
	return (0);
}

int				fmt_putstrlit(t_writer *writer, t_token *token, va_list vlist)
{
	(void)vlist;
	return (writer_write(writer, token->value.as_literal.value, token->value.as_literal.length));
}
