/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstpop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 14:36:23 by nloomans       #+#    #+#                */
/*   Updated: 2019/04/04 14:37:22 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstpop(t_list **alst)
{
	t_list	*node;

	node = *alst;
	*alst = (*alst)->next;
	return (node);
}
