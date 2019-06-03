/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   runner.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 15:17:29 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/03 15:37:52 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "writer.h"
#include "fmt.h"
#include <libft.h>
#include <stdio.h>

void		debug_token(t_token *token)
{
	const char *lookup[] =
	{
		"E_TXT",
		"E_PERCENT",
		"E_INT",
		"E_STR",
		"E_UNS",
		"E_PTR",
		"E_HEX",
		"E_CHR",
		"E_OCT",
		"E_FLOAT",
		"E_MEMORY",
		"E_COLOR",
		"E_INVALID",
	};
	printf("\n\nToken:\n");
	printf("- Size:  % 2d\n", (int)token->size);
	printf("- Length:% 2d\n", (int)token->s_length);
	printf("- Precis:% 2d\n", (int)token->precision);
	printf("- Width: % 2d\n", (int)token->width);
	printf("- Flags: % 2d ( ", token->flags);
	if (token->flags & FLAGS_HASH)
		printf("HASH ");
	if (token->flags & FLAGS_CAPITAL)
		printf("CAPITAL ");
	if (token->flags & FLAGS_LEFTALIGN)
		printf("LEFTALIGN ");
	if (token->flags & FLAGS_PLUS)
		printf("PLUS ");
	if (token->flags & FLAGS_PRECISION)
		printf("PRECISION ");
	if (token->flags & FLAGS_SPACE)
		printf("SPACE ");
	if (token->flags & FLAGS_ZEROPAD)
		printf("ZEROPAD ");
	printf(")\n");
	printf("- Type:   %s\n", lookup[token->type]);
}

void			run_token(t_writer *writer, va_list vlist, t_token *token)
{
	const t_formatter	fmts[] = {
		fmt_putstrlit,
		fmt_putpercent,
		fmt_putnbr,
		fmt_putstr,
		fmt_putuns,
		fmt_putptr,
		fmt_puthex,
		fmt_putchr,
		fmt_putoct,
		fmt_putflt,
		fmt_printmemory,
		fmt_putcolor,
	};

	(void)debug_token;
	fmts[token->type](writer, token, vlist);
}
