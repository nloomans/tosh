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

enum e_pipe_ends{
	read_from = 0,
	write_to = 1,
};

typedef uint8_t	(t_builtin)(int, char **, t_env *const);

struct s_builtin_tbl{
	const char	*name;
	t_builtin	*ptr;
};

struct s_exec__state{
	// t_error		err;
	bool		must_halt; //terminate loop when user hit ctrl-c and it was handled already
	t_list_meta	pid_list;
};

struct s_child{
	pid_t				pid;
	struct s_list_conn	conn;
};

struct s_redirection{
	int			origin;
	int			dest;
	t_list_conn	conn;
}; //only handles basic numbers for now

struct s_all_redirection{
	int			back_up_fd[3];
	t_list_meta	redirections;
};

#define			BACKUP_STDIN	(1000)
#define			BACKUP_STDOUT	(1001)
#define			BACKUP_STDERR	(1002)

struct s_program_prereq{
	char		**arg;
	int			arg_count;
	char		**env;
	struct s_all_redirection\
				fd_data;
};

struct s_child	*unpack_child(const struct s_list_conn *const node);

t_error			exec__expand_family(t_list_meta *const pid_list,
					const pid_t pid);
void			exec__kill_all_children(t_list_meta *const pid_list);

t_error			exec__child_process_control(t_env *const env,
					struct s_exec__state *const status);

t_error			exec__handle_redirections(
					struct s_all_redirection *const tracker,
					const struct s_simple_command *const command);

t_error			exec__set_arguments(struct s_program_prereq *const all_arg,
					const struct s_simple_command *const command,
					const t_env *const env);
void			exec__clear_arguments(struct s_program_prereq *const all_arg);

t_builtin		*exec__identify_builtin(const char *const name);
void			exec__identify_executable(
					const struct s_program_prereq *const all_arg,
					const t_env *const env);

t_error			exec__sequence(struct s_exec__state *const status,
					const struct s_pipe_sequence *const sequence,
					t_env *const env);

t_error			exec__single(struct s_exec__state *const status,
					const struct s_simple_command *const command,
					t_env *const env);

#endif
		
