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

enum	e_pipe_ends{
	read_from = 0,
	write_to = 1,
};

typedef uint8_t	(t_builtin)(int, char **, t_env *const);

struct	s_builtin_tbl{
	const char	*name;
	t_builtin	*ptr;
};

struct	s_exec_state{
	bool		must_halt;
	t_list_meta	pid_list;
};//this struct should possibly be deleted

struct	s_child{
	pid_t				pid;
	struct s_list_conn	conn;
};

struct	s_redirection{
	int					origin_fd;
	int					dest_fd;
	t_list_conn			conn;
};

struct	s_all_redirection{ 
	t_list_meta			redirect_tracker;
};

typedef t_error			(t_redirect_func)(t_list_meta *const,
							const int,
							const struct s_io_file *const);

struct	s_redirection_kvp{
	int					default_fd;
	t_redirect_func		*handler;
};

# define BACKUP_STDIN	1000
# define BACKUP_STDOUT	1001
# define BACKUP_STDERR	1002

struct	s_program_prereq{
	char				**arg;
	int					arg_count;
	char				**env;
	struct s_all_redirection\
						fd_data;
	t_list_meta			redir_tracker;
};

/*
**		////process_control.h////
*/
struct s_child			*unpack_child(const struct s_list_conn *const node);

t_error					exec__child_process_control(t_env *const env,
							struct s_exec_state *const status);

t_error					exec__expand_family(t_list_meta *const pid_list,
							const pid_t pid);
void					exec__kill_all_children(t_list_meta *const pid_list,
							const int sig);
void					exec__kill_child(struct s_child *const child_process,
							const int sig);

/*
**		////redirection.h////
*/
t_error					exec__handle_redirections(
							t_list_meta *const tracker_lst,
							const struct s_simple_command *const command);
bool					exec__is_protected_fd(const int fd);
struct s_redirection	*unpack_tracker(const t_list_conn *const node);

t_error					exec__add_tracker(const int dest_fd,
							const int new_fd,
							t_list_meta *const tracker_lst);
t_error					exec__undo_and_del_redir(
							t_list_meta *const tracker_lst);

t_error					redirect_in(t_list_meta *const tracker_lst,
							const int first_fd,
							const struct s_io_file *const current_redirect);

t_error					redirect_out(t_list_meta *const tracker_lst,
							const int first_fd,
							const struct s_io_file *const current_redirect);
t_error					redirect_out_append(t_list_meta *const tracker_lst,
							const int first_fd,
							 const struct s_io_file *const current_redirect);

/*
**		////set_arg.h////
*/
t_error					exec__set_arguments(
							struct s_program_prereq *const all_arg,
							const struct s_simple_command *const command,
							const t_env *const env);
t_error					exec__clear_arguments(
							struct s_program_prereq *const all_arg);

/*
**		exec types
*/
t_builtin				*exec__identify_builtin(const char *const name);
void					exec__identify_executable(
							const struct s_program_prereq *const all_arg,
							const t_env *const env);

/*
**		iterator types
*/
t_error					exec__sequence(struct s_exec_state *const status,
							const struct s_pipe_sequence *const sequence,
							t_env *const env);

t_error					exec__single(struct s_exec_state *const status,
							const struct s_simple_command *const command,
							t_env *const env);

#endif
