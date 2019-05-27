/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 15:56:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/27 19:09:14 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "token.h"

typedef struct	e_char2descriptor
{
	char			c;
	t_descriptor	descriptor;
}				t_char2descriptor;

int		parse_atoi(char **stream);
int		parse_atoi_wildcard(char **stream);

#endif
