/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:27:11 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/26 23:07:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <sys/types.h>

ssize_t	ft_vprintf(char *fmt, va_list vlist);
ssize_t	ft_printf(char *fmt, ...);
ssize_t	ft_fprintf(int fd, char *fmt, ...);
ssize_t	ft_asprintf(char **dest, char *fmt, ...);
ssize_t	ft_snprintf(char **dest, ssize_t capacity, char *fmt, ...);
ssize_t	ft_sprintf(char **dest, char *fmt, ...);

#endif
