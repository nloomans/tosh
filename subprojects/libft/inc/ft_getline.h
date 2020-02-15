/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getline.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 14:58:41 by nloomans      #+#    #+#                 */
/*   Updated: 2019/11/28 14:58:42 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETLINE_H
# define FT_GETLINE_H
# define BUFF_SIZE 64

typedef struct	s_fd_state_store
{
	int			fd;
	char		*fd_state;
}				t_fd_state_store;

#endif
