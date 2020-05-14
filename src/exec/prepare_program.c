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


t_error		exec__prepare_program(struct s_program_stat *const all_arg,
				const struct s_simple_command *const command,
				const t_env *const env)
{
	t_error	err;

	all_arg->env = env_to_envp(env);
	if (all_arg->env == NULL)
	{
		return (errorf("unable to allocate memory"));
	}
	err = exec__handle_redirections(command);

	return (err);
}
