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

static t_error	initialize_arguments(struct s_program_prereq *const all_arg,
					const struct s_simple_command *const command,
					const t_env *const env) //placeholder
{
	t_error	err;

	size_t	len;
	struct s_cmd_suffix *iter;

	err = error_none();
	iter = command->suffix;
	len = 1;
	while (iter)
	{
		if (iter->word)
			len++;
		iter = iter->suffix;
	}
	all_arg->arg = ft_memalloc((len + 1)* sizeof(char *));
	if (all_arg->arg == NULL)
	{
		return (errorf("unable to allocate memory"));
	}
	all_arg->arg_count = len;
	len = 1;
	all_arg->arg[0] = ft_strdup(command->name);
	iter = command->suffix;
	while (iter)
	{
		if (iter->word)
		{
			all_arg->arg[len] = ft_strdup(iter->word);
			len++;
		}
		iter = iter->suffix;
	}
	(void)env;
	return (err);
}

t_error			exec__set_arguments(struct s_program_prereq *const all_arg,
					const struct s_simple_command *const command,
					const t_env *const env)
{
	t_error	err;

	all_arg->env = env_to_envp(env);
	if (all_arg->env == NULL)
	{
		return (errorf("unable to allocate memory"));
	}
	err = exec__handle_redirections(&all_arg->redir_tracker, command);
	if (is_error(err))
	{
		exec__clear_arguments(all_arg);
		return (err);
	}
	err = initialize_arguments(all_arg, command, env);
	if (is_error(err))
	{
		exec__clear_arguments(all_arg);
		return (err);
	}
	return (err);
}
