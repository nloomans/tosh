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

#ifndef PRIVATE_H
# define PRIVATE_H

# include "exec.h"

struct s_exec_state{
	// t_error		err;
	bool		must_halt; //terminate loop when user hit ctrl-c and it was handled already
	t_list_meta	pid_list;
};

struct s_child{
	__pid_t				pid;
	struct s_list_conn	conn;
};

struct s_child	*unpack_child(const struct s_list_conn *const node);

t_error			exec__expand_family(t_list_meta *const pid_list,
					const __pid_t pid);


t_error			exec__sequence(struct s_exec_state *const status,
					const struct s_pipe_sequence *sequence,
					const t_env *const env);

#endif
		