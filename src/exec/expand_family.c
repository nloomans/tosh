/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tosh-21Shell                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

t_error		exec__expand_family(t_list_meta *const pid_list, const __pid_t pid)
{
	struct s_child	*new;

	new = ft_memalloc(sizeof(*new));
	if (new == NULL)
	{
		return (errorf("unable to allocate memory"));
	}
	new->pid = pid;
	ft_list_insert(pid_list, pid_list->last, new);
	return (error_none());
}
