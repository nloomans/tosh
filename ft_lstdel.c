/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 13:28:00 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/30 16:27:28 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

void	ft_lstdel(t_list **alst, void del(void *, size_t))
{
	if (*alst == NULL)
		return ;
	ft_lstdel(&(*alst)->next, del);
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
