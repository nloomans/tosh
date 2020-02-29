/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_unlink.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 19:51:24 by nloomans      #+#    #+#                 */
/*   Updated: 2020/02/21 19:51:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_unlink(
			t_list_meta *meta,
			t_list_conn *conn)
{
	if (meta->first == conn)
		meta->first = conn->next;
	if (meta->last == conn)
		meta->last = conn->prev;
	if (conn->prev)
		conn->prev->next = conn->next;
	if (conn->next)
		conn->next->prev = conn->prev;
	meta->len--;
}
