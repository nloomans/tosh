/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:33:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/22 16:44:45 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H

# include "writer.h"
# include "token.h"

typedef int(*t_formatter)(t_writer *writer, t_token *token, va_list vlist);


int				fmt_putstr(t_writer *writer, t_token *token, va_list vlist);

#endif
