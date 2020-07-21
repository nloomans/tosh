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

#include <ft_printf.h>

#include "../input/input.h"
#include "private.h"

t_error		expand_tape(char **const memory_tape,
				char **const new_text)
{
	char						*holder;

	if (ft_asprintf(&holder, "%s\n%s", *memory_tape, *new_text) == -1)
	{
		ft_strdel(new_text);
		return (errorf("unable to allocate memory"));
	}
	ft_strdel(memory_tape);
	*memory_tape = holder;
	return (error_none());
}

t_error		request_qoutation_completion(char **const memory_tape,
				const char qoute)
{
	struct s_input_read_result	new;
	t_error						err;

	while (true)
	{
		err = input_read(&new, "> ", 2);
		if (is_error(err))
			return (err);
		if (new.exit_reason != INPUT_EXIT_REASON_SUBMIT)
		{
			ft_strdel(&new.text);
			if (new.exit_reason == INPUT_EXIT_REASON_CANCEL)
				return (errorf("User hit Ctrl-C"));
			return (errorf("unexpected EOF while looking for`%c'", qoute));
		}
		err = expand_tape(memory_tape, &new.text);
		if (is_error(err))
			return (err);
		if (ft_strchr(new.text, qoute) != NULL)
			break ;
	}
	ft_strdel(&new.text);
	return (error_none());
}

t_error		lexer_handler(
				t_list_meta *const all_token,
				char **const memory_tape)
{
	t_tok_machine_state	state;
	t_error				err;
	char				missing_qoute;

	while (1)
	{
		if (lexer_tokenize(&state, all_token, *memory_tape) == -1)
		{
			return (errorf("lexer: could not allocate memory"));
		}
		if (state == eof)
		{
			break ;
		}
		lexer_clear(all_token);
		missing_qoute = '\"';
		if (state == unterm_single)
			missing_qoute = '\'';
		err = request_qoutation_completion(memory_tape, missing_qoute);
		if (is_error(err))
		{
			return (errorf("lexer: %s", err.msg));
		}
	}
	return (error_none());
}
