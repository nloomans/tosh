/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 13:44:04 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/29 13:49:37 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** TODO: Remove this function. It simply exists because it's required to get
** the bonus points.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	ft_lstpush(alst, new);
}
