/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   runner.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 15:17:29 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/22 16:32:26 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

#include "token.h"
#include "writer.h"
#include <libft.h>


int				run_token(t_writer *writer, va_list vlist, t_token *token)
{
	char *tok_lookup[] = {
		"E_LITERAL",
		"E_PARAMETER"
	};
	char *lit_lookup[] = {
		"E_STRING",
		"E_PERCENT",
	};
	char *par_lookup[] = {
		"E_INT",
		"E_STR",
	};
	printf("Found: \x1b[36m%s\x1b[0m; ", tok_lookup[token->type]);
	if (token->type == E_LITERAL)
	{
		printf("Namely, \x1b[32m%s\x1b[0m (%s)\n", lit_lookup[token->value.as_literal.type], 
			ft_strsub(token->value.as_literal.value, 0, token->value.as_literal.length));
	}
	else
	{
		printf("Namely, \x1b[32m%s\x1b[0m\n", par_lookup[token->value.as_parameter.type]);
	}
	(void)writer;
	(void)vlist;
	(void)token;
	return (0);
}
