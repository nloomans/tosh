/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   runner.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 15:17:29 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/22 21:03:55 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "writer.h"
#include "fmt.h"
#include <libft.h>

int				run_token(t_writer *writer, va_list vlist, t_token *token)
{
	const t_formatter	fmts[] = {
		fmt_putstrlit,
		fmt_putpercent,
		fmt_putnbr,
		fmt_putstr,
		fmt_putnbr,
		fmt_putptr,
		fmt_puthex,
		fmt_putchr,
		fmt_putoct
	};

	return (fmts[token->type](writer, token, vlist));
}
