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

struct	s_simple_command
{
	struct s_cmd_prefix		*prefix;
	char					*word;
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

#endif
