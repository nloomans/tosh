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
void			exec__kill_all_children(t_list_meta *const pid_list);

t_error			exec__child_process_control(t_list_meta *const pid_list,
					t_env *const env,
					struct s_exec_state *const status);

t_error			exec__sequence(struct s_exec_state *const status,
					const struct s_pipe_sequence *sequence,
					t_env *const env);

#endif
		
