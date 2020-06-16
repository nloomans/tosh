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

#include <unistd.h>

#include "private.h"

void	exec__clear_arguments(struct s_program_prereq *const all_arg)
{
	close(BACKUP_STDIN);
	close(BACKUP_STDOUT);
	close(BACKUP_STDERR);
	if (all_arg->arg)
	{
		ft_arraydel((void ***)&all_arg->arg, &ft_memdel);
	}
	if (all_arg->env)
	{
		ft_arraydel((void ***)&all_arg->env, &ft_memdel);
	}
	all_arg->arg_count = 0;
}
