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

#ifndef PARSER_H
# define PARSER_H

# include "../error/error.h"
# include "../lexer/lexer.h"

struct	s_complete_command
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
	REDIRECT_IN_AND,
	REDIRECT_OUT,
	REDIRECT_OUT_APPEND,
	REDIRECT_OUT_AND,
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
	char						*here_end;
	char						*contents;
};

t_error	parser_parse(
			struct s_complete_command **const complete_command,
			t_list_meta *const all_token);
void	parser_del(struct s_complete_command **const complete_command);

#endif
