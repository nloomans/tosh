/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 18:27:26 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/20 18:28:29 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

/*
** string.h
*/

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);

/*
** stdlib.h
*/

int		ft_atoi(const char *str);

/*
** ctype.h
*/

int		ft_isspace(int c);

/*
** custom
*/

char	*ft_strdropwhile(const char *str, int should_skip(int c));

#endif
