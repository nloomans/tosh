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

static size_t	calculate_array(const struct s_simple_command *const command)
{
	size_t						len;
	const struct s_cmd_suffix	*iter;

	if (command->name == NULL)
		return (0);
	len = 1;
	iter = command->suffix;
	while (iter)
	{
		if (iter->word)
			len++;
		iter = iter->suffix;
	}
	return (len);
}

static t_error	initialize_arguments(struct s_program_prereq *const all_arg,
					const struct s_simple_command *const command)
{
	size_t						len;
	const struct s_cmd_suffix	*iter;

	len = calculate_array(command);
	all_arg->argv = ft_memalloc((len + 1) * sizeof(char *));
	if (all_arg->argv == NULL)
		return (errorf("unable to allocate memory"));
	all_arg->arg_count = len;
	len = 1;
	all_arg->argv[0] = ft_strdup(command->name);
	if (all_arg->argv[0] == NULL)
		return (errorf("unable to allocate memory"));
	iter = command->suffix;
	while (iter)
	{
		if (iter->word)
		{
			all_arg->argv[len] = ft_strdup(iter->word);
			if (all_arg->argv[len] == NULL)
				return (errorf("unable to allocate memory"));
			len++;
		}
		iter = iter->suffix;
	}
	return (error_none());
}

t_error			exec__set_arguments(struct s_program_prereq *const all_arg,
					const struct s_simple_command *const command,
					const t_env *const env)
{
	t_error	err;

	all_arg->envp = env_to_envp(env);
	if (all_arg->envp == NULL)
	{
		return (errorf("unable to allocate memory"));
	}
	err = exec__handle_redirections(&all_arg->redir_tracker, command, env);
	if (is_error(err))
	{
		exec__clear_arguments(all_arg);
		return (err);
	}
	if (command->name)
	{
		err = initialize_arguments(all_arg, command);
		if (is_error(err))
		{
			exec__clear_arguments(all_arg);
			return (err);
		}
	}
	return (err);
}
