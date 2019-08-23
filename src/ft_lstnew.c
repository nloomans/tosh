/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 11:24:48 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/29 13:18:56 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *new;

	new = (t_list *)ft_memalloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
		return (new);
	new->content_size = content_size;
	new->content = ft_memalloc(content_size);
	if (new->content == NULL)
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	ft_memcpy(new->content, content, content_size);
	return (new);
}
