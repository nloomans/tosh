/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:59:48 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/20 15:40:16 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITER_H
# define WRITER_H
# include <stddef.h>

typedef struct	s_writer
{
	ssize_t	(*write)(void *state, char *str, size_t length);
	void	*state;
}				t_writer;

ssize_t			writer_write(t_writer *writer, char *str, size_t length);

/*
** Write to stdout (1)
*/
typedef int		t_writer_fd_state;
ssize_t			writer_fd_write(void *state, char *str, size_t length);

/*
** Write to auto-allocated string
** TODO: implement Vector
*/
typedef struct	s_writer_alloc_state
{
	char	**str_ptr;
	size_t	len;
}				t_writer_alloc_state;
ssize_t			writer_alloc_write(void *state, char *str, size_t length);



#endif
