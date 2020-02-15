/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 13:21:37 by nloomans       #+#    #+#                */
/*   Updated: 2019/04/09 17:58:15 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_getline.h"

/*
** Keep reading BUFF_SIZE and appending it to fd_state until fd_state contains
** c. If fd_state already contains c no action is preformed.
**
** Returns 1 if fd_state contains bytes at the end of the operation, 0 if it
** does not (e.g there was nothing to read). Returns -1 on error.
*/

static int	read_until_char(char **fd_state, int fd, char c)
{
	char	buffer[BUFF_SIZE];
	ssize_t	bytes_read;

	while (ft_strchr(*fd_state, c) == NULL)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
			return (-1);
		if (bytes_read == 0)
			break ;
		if (!ft_strappendbytes(fd_state, buffer, (size_t)bytes_read))
			return (-1);
	}
	return (ft_strlen(*fd_state) > 0);
}

/*
** Assign line to a new string containing the first line in fd_state excluding
** the newline character. Remove that string including the newline character
** from fd_state.
**
** If no newline was found, the entire string will be copied to line and
** fd_state will be freed and set to NULL.
**
** Returns 1 on success and 0 on error.
*/

static int	consume_line(char **line, char **fd_state)
{
	char	*newline_ptr;
	char	*fd_state_ptr;

	newline_ptr = ft_strchr(*fd_state, '\n');
	*line = (newline_ptr == NULL)
		? ft_strdup(*fd_state)
		: ft_strsub(*fd_state, 0, newline_ptr - *fd_state);
	if (*line == NULL)
		return (0);
	if (newline_ptr == NULL)
		ft_strdel(fd_state);
	else
	{
		fd_state_ptr = *fd_state;
		*fd_state = ft_strdup(newline_ptr + 1);
		ft_strdel(&fd_state_ptr);
		if (*fd_state == NULL)
			return (0);
	}
	return (1);
}

/*
** Get the next line and store it in line.
**
** fd_state is the internal state of this function. It points to a char* which
** MUST be initialized to NULL and MUST be consistent between calls of the same
** fd. fd_state will be freed by this function on error or finish.
*/

static int	get_next_line_with_state(const int fd, char **line, char **fd_state)
{
	int			ret;

	if (line == NULL)
		return (-1);
	*line = NULL;
	if (*fd_state == NULL)
		*fd_state = ft_strnew(0);
	if (*fd_state == NULL)
		return (-1);
	ret = read_until_char(fd_state, fd, '\n');
	if (ret <= 0)
	{
		ft_strdel(line);
		ft_strdel(fd_state);
		return (ret);
	}
	if (!consume_line(line, fd_state))
	{
		ft_strdel(line);
		ft_strdel(fd_state);
		return (-1);
	}
	return (ret);
}

/*
** Get the next line and store it in line.
**
** This function keeps track of the fd_state_store for every fd and calls
** get_next_line_with_state using the correct fd_state. It mallocs and frees
** fd_state_store if necessary.
*/

static int	get_next_line_c(const int fd, char **line, t_list **state)
{
	t_fd_state_store	new_fd_state;
	int					ret;
	t_list				*next_ptr;

	if (*state == NULL)
	{
		new_fd_state.fd = fd;
		new_fd_state.fd_state = NULL;
		*state = ft_lstnew(&new_fd_state, sizeof(new_fd_state));
		if (*state == NULL)
			return (-1);
	}
	else if (((t_fd_state_store *)(*state)->content)->fd != fd)
		return (get_next_line_c(fd, line, &(*state)->next));
	ret = get_next_line_with_state(fd, line,
			&((t_fd_state_store *)(*state)->content)->fd_state);
	if (ret <= 0)
	{
		ft_memdel(&(*state)->content);
		next_ptr = (*state)->next;
		ft_memdel((void **)state);
		*state = next_ptr;
	}
	return (ret);
}

int			ft_getline(const int fd, char **line)
{
	static t_list	*state;

	return (get_next_line_c(fd, line, &state));
}
