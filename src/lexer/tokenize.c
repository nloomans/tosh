/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: aholster <aholster@student.codam.nl>          +:+                    */
/*       ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*       nloomans <nloomans@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "private.h"

static int	add_char(struct s_string *const cur_token, const char c)
{
	char	*temp;

	if (cur_token->capacity == cur_token->len + 1)
	{
		temp = ft_memalloc(cur_token->capacity * 2);
		if (temp == NULL)
		{
			return (-1);
		}
		ft_memcpy(temp, cur_token->buffer, cur_token->len);
		free(cur_token->buffer);
		cur_token->buffer = temp;
		cur_token->capacity *= 2;
	}
	cur_token->buffer[cur_token->len] = c;
	cur_token->len++;
	cur_token->buffer[cur_token->len] = '\0';
	return (0);
}

static int	delimit(
				t_list_meta *const all_token,
				struct s_string *const cur_token,
				const enum e_token_type delimit_type)
{
	struct s_token	*new_token;

	new_token = ft_memalloc(sizeof(*new_token));
	if (new_token)
	{
		new_token->string = ft_memalloc(cur_token->len + 1);
		if (new_token->string)
		{
			ft_memcpy(new_token->string, cur_token->buffer, cur_token->len + 1);
			new_token->type = delimit_type;
			ft_list_insert(all_token, all_token->last, &new_token->conn);
			cur_token->len = 0;
			return (0);
		}
		free(new_token);
	}
	return (-1);
}

static void	clean_all(
				t_list_meta *const all_token,
				struct s_string *const cur_token)
{
	ft_strdel(&cur_token->buffer);
	ft_bzero(cur_token, sizeof(*cur_token));
	lexer_clear(all_token);
}

static int	handle_current_state(
				t_list_meta *const all_token,
				struct s_string *const cur_token,
				const struct s_fsm_rule cur_rule,
				const unsigned char current_character)
{
	if (cur_rule.delimit != UNDETERMINED)
	{
		if (delimit(all_token, cur_token, cur_rule.delimit) == -1)
		{
			clean_all(all_token, cur_token);
			return (-1);
		}
	}
	if (cur_rule.add_char == true)
	{
		if (add_char(cur_token, current_character) == -1)
		{
			clean_all(all_token, cur_token);
			return (-1);
		}
	}
	return (0);
}

int			lexer_tokenize(
				t_list_meta *const all_token,
				char const *memory_tape)
{
	t_tok_machine_state			state;
	struct s_string				cur_token;
	struct s_fsm_state			cur_state;
	struct s_fsm_rule			cur_rule;

	state = blank;
	ft_bzero(all_token, sizeof(*all_token));
	ft_bzero(&cur_token, sizeof(cur_token));
	cur_token.buffer = ft_memalloc(INITIAL_BUFF);
	if (cur_token.buffer == NULL)
		return (-1);
	cur_token.capacity = INITIAL_BUFF;
	while (state != eof)
	{
		cur_state = g_machine_table[state];
		cur_rule = (cur_state.rules[(*memory_tape & 0xff)].new_state == noop)
			? cur_state.catch_rule
			: cur_state.rules[(*memory_tape & 0xff)];
		if (handle_current_state(all_token, &cur_token, cur_rule, *memory_tape))
			return (-1);
		state = cur_rule.new_state;
		memory_tape++;
	}
	return (0);
}
