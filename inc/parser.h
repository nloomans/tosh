/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 15:56:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/23 00:12:19 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "token.h"


typedef	enum	e_fsm
{
	ST_ANY = 0,
	ST_PARAM = 1,
	ST_STR_LIT = 2,
}				t_fsm;

typedef	int(*t_st_handler)(t_fsm *st, t_token *dest, char **stream);

int				parse_atoi(char **stream);

#endif
