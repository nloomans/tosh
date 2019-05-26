/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:33:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/27 01:25:48 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H

# include "writer.h"
# include "token.h"
# include "color.h"

typedef void	(*t_formatter)(t_writer *writer, t_token *token, va_list vlist);


void			fmt_putstr(t_writer *writer, t_token *token, va_list vlist);
void			fmt_putstrlit(t_writer *writer, t_token *token, va_list vlist);
void			fmt_putpercent(t_writer *writer, t_token *token, va_list vlist);
void			fmt_putnbr(t_writer *writer, t_token *token, va_list vlist);
void			fmt_putcolor(t_writer *writer, t_token *token, va_list vlist);
void			fmt_putptr(t_writer *writer, t_token *token, va_list vlist);
void			fmt_puthex(t_writer *writer, t_token *token, va_list vlist);
void			fmt_putoct(t_writer *writer, t_token *token, va_list vlist);
void			fmt_putchr(t_writer *writer, t_token *token, va_list vlist);
void			fmt_putflt(t_writer *writer, t_token *token, va_list vlist);
void			fmt_printmemory(
					t_writer *writer,
					t_token *token,
					va_list vlist);

void			intern_fmt_puthex(
					t_writer *writer,
					unsigned long long value,
					int caps);
void			intern_fmt_pad(t_writer *writer, char c, size_t amt);
char			intern_to_hex(char num, int caps);
void			intern_pop_wildcards(t_token *token, va_list vlist);
void			intern_fmt_pad_auto(
					t_writer *writer,
					char c,
					size_t pad_amount,
					size_t length);
void			intern_fmt_pad_left(
					t_writer *writer,
					t_token *token,
					char c,
					size_t length);
void			intern_fmt_pad_right(
					t_writer *writer,
					t_token *token,
					char c,
					size_t length);
int				intern_hex_size(long long n);
void			intern_fmt_color(t_writer *writer, t_color color);
size_t			intern_ntoa(char *buf_out, unsigned long long n, unsigned base, int caps);
void			intern_auto_floor(t_token *token, unsigned long long* n);


#endif
