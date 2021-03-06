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

#ifndef PRIVATE_H
# define PRIVATE_H

# include <stdbool.h>

# include "lexer.h"

/*
**	noop shall be mathematically 0 and not overlap w/ other states.
*/

typedef enum	e_tok_machine_state{
	noop,
	blank,
	word,
	io_number,
	redir_left,
	redir_right,
	operator_exit,
	quote_single,
	quote_double,
	comment,
	eof,
	unterm_single,
	unterm_double,
}				t_tok_machine_state;

struct			s_fsm_rule
{
	t_tok_machine_state	new_state;
	enum e_token_type	delimit;
	bool				add_char;
};

struct			s_fsm_state
{
	struct s_fsm_rule	rules[256];
	struct s_fsm_rule	catch_rule;
};

extern const struct s_fsm_state g_machine_table[];

int				lexer_tokenize(t_tok_machine_state *const state,
					t_list_meta *const all_token,
					char const *memory_tape);

#endif
