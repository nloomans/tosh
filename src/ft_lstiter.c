/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:43:38 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/30 17:41:56 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void f(t_list *elem))
{
	if (lst == NULL)
		return ;
	f(lst);
	ft_lstiter(lst->next, f);
}
