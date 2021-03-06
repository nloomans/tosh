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

#include <criterion/criterion.h>
#include <string.h>
#include "test.h"

#define		ENSURE_PTRS(a, b) do											\
{																			\
	if (a == NULL && b == NULL)												\
		return ;															\
	if (a == NULL)															\
	{																		\
		cr_expect_fail("got NULL but expected a value in %s", __func__);	\
		return ;															\
	}																		\
	if (b == NULL)															\
	{																		\
		cr_expect_fail("got a value but expected NULL in %s", __func__);	\
		return ;															\
	}																		\
} while (0)

void		check_string(const char *const a, const char *const b)
{
	if (a || b)
		cr_expect_str_eq(a, b);
}

void		check_complete_command(
				const struct s_complete_command *const a,
				const struct s_complete_command *const b)
{
	ENSURE_PTRS(a, b);
	check_list(a->list, b->list);
}

void		check_list(
				const struct s_list *const a,
				const struct s_list *const b)
{
	ENSURE_PTRS(a, b);
	check_list(a->list, b->list);
	check_pipe_sequence(a->pipe_sequence, b->pipe_sequence);
}

void		check_pipe_sequence(
				const struct s_pipe_sequence *const a,
				const struct s_pipe_sequence *const b)
{
	ENSURE_PTRS(a, b);
	check_pipe_sequence(a->pipe_sequence, b->pipe_sequence);
	check_simple_command(a->simple_command, b->simple_command);
}

void		check_simple_command(
				const struct s_simple_command *const a,
				const struct s_simple_command *const b)
{
	ENSURE_PTRS(a, b);
	check_cmd_prefix(a->prefix, b->prefix);
	check_string(a->name, b->name);
	check_cmd_suffix(a->suffix, b->suffix);
}

void		check_cmd_prefix(
				const struct s_cmd_prefix *const a,
				const struct s_cmd_prefix *const b)
{
	ENSURE_PTRS(a, b);
	check_cmd_prefix(a->prefix, b->prefix);
	check_io_redirect(a->redirect, b->redirect);
}

void		check_cmd_suffix(
				const struct s_cmd_suffix *const a,
				const struct s_cmd_suffix *const b)
{
	ENSURE_PTRS(a, b);
	check_cmd_suffix(a->suffix, b->suffix);
	check_io_redirect(a->redirect, b->redirect);
	check_string(a->word, b->word);
}

void		check_io_redirect(
				const struct s_io_redirect *const a,
				const struct s_io_redirect *const b)
{
	ENSURE_PTRS(a, b);
	cr_expect_eq(a->fd, b->fd);
	check_io_file(a->file, b->file);
	check_io_here(a->here, b->here);
}

void		check_io_file(
				const struct s_io_file *const a,
				const struct s_io_file *const b)
{
	ENSURE_PTRS(a, b);
	cr_expect_eq(a->type, b->type);
	check_string(a->filename, b->filename);
}

void		check_io_here(
				const struct s_io_here *const a,
				const struct s_io_here *const b)
{
	ENSURE_PTRS(a, b);
	check_string(a->here_end, b->here_end);
}
