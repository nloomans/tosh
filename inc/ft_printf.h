/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:27:11 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/20 15:46:23 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <sys/types.h>

ssize_t	ft_vprintf(char *fmt, va_list vlist);
ssize_t	ft_printf(char *fmt, ...);
ssize_t	ft_aprintf(char **dest, char *fmt, ...);

#endif
