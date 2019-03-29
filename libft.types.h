/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.types.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 11:20:14 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/29 11:22:51 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

# include <string.h>

struct					s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
};
typedef struct s_list	t_list;

#endif
