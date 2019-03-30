/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:46:43 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/30 17:08:06 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *f(t_list *elem))
{
	t_list *dup;

	if (lst == NULL)
		return (NULL);
	dup = ft_lstnew(lst->content, lst->content_size);
	if (dup == NULL)
		return (NULL);
	dup = f(dup);
	dup->next = ft_lstmap(lst->next, f);
	if (dup->next == NULL && lst->next != NULL)
	{
		ft_memdel((void **)&dup);
		return (NULL);
	}
	return (dup);
}
