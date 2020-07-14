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

#include "quote_and_expansion.h"

#include <stdio.h>
static void		get_next_rule(
					const struct s_quote_fsm_rule **const acur_rule,
					unsigned char const input_char,
					const enum e_machine_state old_state,
					const t_machine_def *machine)
{
	const t_machine_def	*current_subsection;

	current_subsection = &machine[old_state];
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
					t_env *const env)
{
	enum e_machine_state			current_state;
	const struct s_quote_fsm_rule	*current_rule;

	current_state = FIRST_CHAR;
	while (current_state != EOS && current_state != QUOTE_INCOMPLETE)
	{
		get_next_rule(&current_rule, *input_tape, current_state, machine);
		if (current_rule->ignore_char == false)
		{
			printf("%c", *input_tape);
		}
		if (machine[current_state].can_env_expand && *input_tape == '$')
		{
			
		}
		input_tape++;
		current_state = current_rule->new_state;
	}
	printf("\n");
	(void)env;
	(void)output_tape;
	if (current_state == QUOTE_INCOMPLETE)
	{
		return (errorf("parser error: qoutation incomplete"));
	}
	return (error_none());
}

t_error     	replacer_fsm(char **const tape,
            	    const t_machine_def *machine,
            	    t_env *const env)
{
	char	*new_tape;
	t_error	err;

	new_tape = NULL;
	err = iter_fsm(*tape, &new_tape, machine, env);
	if (is_error(err))
	{
		return (errorf("%s: %s", *tape, err.msg));
	}
	//ft_strreplace(tape, new_tape);
	return (error_none());
}
