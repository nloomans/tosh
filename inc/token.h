/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 14:02:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/22 20:43:15 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "writer.h"
# include <stdarg.h>
# include <sys/types.h>

typedef enum	e_token_descriptor
{
	E_LITERAL,
	E_PARAMETER,
}				t_token_descriptor;

typedef enum	e_literal_descriptor
{
	E_STRING,
	E_PERCENT,
}				t_literal_descriptor;

typedef enum	e_parameter_descriptor
{
	E_INT,
	E_STR,
	E_UNS,
	E_PTR,
	E_HEX,
	E_CHR,
	E_OCT,
}				t_parameter_descriptor;

typedef struct	s_literal
{
	t_literal_descriptor	type;
	char					*value;
	size_t					length;
}				t_literal;

typedef enum	e_size
{
	E_HH,
	E_H,
	E_N,
	E_L,
	E_LL,
}				t_size;

typedef struct	s_parameter
{
	t_parameter_descriptor	type;
	t_size					size;
	int						capitalization;
	int						prefix;
}				t_parameter;

typedef struct	s_token
{
	t_token_descriptor	type;
	union {
		t_literal		as_literal;
		t_parameter		as_parameter;
	}					value;
}				t_token;

int				parse_token(t_token *dest, char **stream);
int				run_token(t_writer *writer, va_list vlist, t_token *token);

#endif
