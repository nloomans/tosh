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

#include <libft.h>

#include "quote_and_expansion.h"

static int		add_to_tape(char **const output_tape,
					const char *const new_addition)
{
	char	*holder;

	if (*output_tape == NULL)
	{
		holder = ft_strdup(new_addition);
	}
	else
	{
		holder = ft_strjoin(*output_tape, new_addition);
	}
	if (holder == NULL)
	{
		return (-1);
	}
	ft_strreplace(output_tape, holder);
	return (0);
}

static int		insert_env_expansion(const char **const ainput_tape,
					char **const output_tape,
					const t_env *const env)
{
	size_t	index;
	char	*holder;
	char	*env_var;

	(*ainput_tape)++;
	if (ft_isdigit(**ainput_tape) || !env_is_key_char(**ainput_tape))
	{
		return (add_to_tape(output_tape, "$"));
	}
	index = 0;
	while (env_is_key_char((*ainput_tape)[index]))
	{
		index++;
	}
	holder = ft_strsub(*ainput_tape, 0, index + 1);
	*ainput_tape += index;
	if (holder == NULL)
		return (-1);
	holder[index] = '\0';
	env_var = env_get_unsafe(env, holder);
	ft_strdel(&holder);
	if (env_var)
		return (add_to_tape(output_tape, env_var));
	return (0);
}

static void		get_next_rule(
					const struct s_quote_fsm_rule **const acur_rule,
					unsigned char const input_char,
					const enum e_machine_state old_state,
					const t_machine_def *machine)
{
	const struct s_quote_fsm_subsection	*current_subsection;

	current_subsection = &machine->all_state[old_state];
	if (current_subsection->rules[input_char].new_state != UNDEF)
	{
		*acur_rule = &current_subsection->rules[input_char];
	}
	else
	{
		*acur_rule = &current_subsection->catch_case;
	}
}

t_error			iter_fsm(const char *input_tape,
					char **const output_tape,
					const t_machine_def *machine,
					const t_env *const env)
{
	enum e_machine_state			current_state;
	const struct s_quote_fsm_rule	*current_rule;

	current_state = machine->first_state;
	while (current_state != EOS && current_state != QUOTE_INCOMPLETE)
	{
		get_next_rule(&current_rule, *input_tape, current_state, machine);
		if (current_rule->env_expand)
		{
			if (insert_env_expansion(&input_tape, output_tape, env) == -1)
				return (errorf("unable to allocate memory"));
		}
		else
		{
			if (current_rule->ignore_char == false && add_to_tape(output_tape,
				(char[2]){*input_tape, '\0'}) == -1)
				return (errorf("unable to allocate memory"));
			input_tape++;
		}
		current_state = current_rule->new_state;
	}
	if (current_state == QUOTE_INCOMPLETE)
		return (errorf("parser error: qoutation incomplete"));
	return (error_none());
}

t_error			replacer_fsm(char **const tape,
					const t_machine_def *machine,
					const t_env *const env)
{
	char	*new_tape;
	t_error	err;

	new_tape = NULL;
	if (machine->first_state == FIRST_CHAR && **tape == '~' && \
		((*tape)[1] == '\0' || (*tape)[1] == '/'))
	{
		new_tape = env_get(env, "HOME");
		err = iter_fsm((*tape) + 1, &new_tape, machine, env);
	}
	else
	{
		err = iter_fsm(*tape, &new_tape, machine, env);
	}
	if (is_error(err))
	{
		return (errorf("%s: %s", *tape, err.msg));
	}
	ft_strreplace(tape, new_tape);
	return (error_none());
}
