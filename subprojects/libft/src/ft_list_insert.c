/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_insert.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 19:48:11 by nloomans      #+#    #+#                 */
/*   Updated: 2020/02/21 19:48:12 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_insert(
			t_list_meta *meta,
			t_list_conn *prev,
			t_list_conn *new)
{
	new->prev = prev;
	if (new->prev)
	{
		new->next = new->prev->next;
		new->prev->next = new;
		if (new->next != NULL)
			new->next->prev = new;
		else
			meta->last = new;
	}
	else
	{
		new->next = meta->first;
		if (new->next)
			new->next->prev = new;
		meta->first = new;
		if (meta->last == NULL)
			meta->last = new;
	}
	meta->len++;
}
