/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 13:23:33 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/29 13:41:24 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void del(void *, size_t))
{
	if ((*alst) == NULL)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
