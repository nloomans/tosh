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

void	exec__clear_arguments(struct s_program_prereqs *const all_arg)
{
	ft_arraydel((void ***)&all_arg->arg, &ft_memdel);
	ft_arraydel((void ***)&all_arg->env, &ft_memdel);
	all_arg->arg_count = 0;
}
