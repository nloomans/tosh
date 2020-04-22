/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   TOSH                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void					env_delete(t_env **const env)
{
	t_list_conn			*current;
	struct s_env_pair	*temp;

	while ((*env)->list.first)
	{
		current = (*env)->list.first;
		ft_list_unlink(&(*env)->list, current);
		temp = unpack_env(current);
		ft_strdel(&temp->key);
		ft_strdel(&temp->value);
		ft_memdel((void **)&temp);
	}
	ft_memdel((void **)env);
}
