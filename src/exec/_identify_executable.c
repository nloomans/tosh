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

#include <stdio.h>
#include <stdlib.h>
void		exec__identify_executable(
				const struct s_program_prereq *const all_arg,
				const t_env *const env)
{
	(void)all_arg;
	(void)env;
	dprintf(2, "running: %s....\n", all_arg->arg[0]);
	exit (5);
}
