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

#ifndef PARSER_H
# define PARSER_H

# include "../lexer/lexer.h"

struct s_complete_command
{
	struct s_list			*list;
};

struct	s_list
{
	struct s_list			*list;
	struct s_pipe_sequence	*pipe_sequence;
};

struct	s_pipe_sequence
{
	struct s_pipe_sequence	*pipe_sequence;
	struct s_simple_command	*simple_command;
};

struct	s_simple_command
{
	struct s_cmd_prefix		*prefix;
	char					*name;
	struct s_cmd_suffix		*suffix;
};

struct	s_cmd_prefix
{
	struct s_cmd_prefix		*prefix;
	struct s_io_redirect	*redirect;
	// for 42 shell
	// const char				*assignment_word;
};

struct	s_cmd_suffix
{
	struct s_cmd_suffix		*suffix;
	struct s_io_redirect	*redirect;
	char					*word;
};

enum	e_io_redirect_type
{
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_OUT_APPEND,
};

struct	s_io_redirect
{
	int					fd;
	struct s_io_file	*file;
	struct s_io_here	*here;
};

struct	s_io_file
{
	enum e_io_redirect_type		type;
	char						*filename;
};

struct	s_io_here
{
	// for 42sh
	// enum e_io_heredoc_type	type;
	char						*here_end;
};

t_error		parser_parse(
				struct s_complete_command **const complete_command,
				bool *const extra_input_requested,
				t_list_meta *const all_token);
void		parser_del(struct s_complete_command **const complete_command);

#endif
