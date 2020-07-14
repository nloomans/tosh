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

#include <fcntl.h>
#include <unistd.h>

#include "../private.h"

t_error		redirect_in(t_list_meta *const tracker_lst,
				const int first_fd,
				const struct s_io_file *const cur_redir)
{
	int		file_fd;
	t_error	err;

	err = redir__open_file(&file_fd, cur_redir->filename, O_RDONLY);
	if (is_error(err))
	{
		return (err);
	}
	err = exec__add_tracker(first_fd, file_fd, tracker_lst);
	close(file_fd);
	if (is_error(err))
	{
		return (errorf("redirecting %s to %d: %s",
			cur_redir->filename, first_fd, err.msg));
	}
	return (error_none());
}

t_error		redirect_out(t_list_meta *const tracker_lst,
				const int first_fd,
				const struct s_io_file *const cur_redir)
{
	int		file_fd;
	t_error	err;

	err = redir__open_file(&file_fd, cur_redir->filename,
		O_WRONLY | O_TRUNC | O_CREAT);
	if (is_error(err))
	{
		return (err);
	}
	err = exec__add_tracker(first_fd, file_fd, tracker_lst);
	close(file_fd);
	if (is_error(err))
	{
		return (errorf("redirecting %s to %d: %s",
			cur_redir->filename, first_fd, err.msg));
	}
	return (error_none());
}

t_error		redirect_out_append(t_list_meta *const tracker_lst,
				const int first_fd,
				const struct s_io_file *const cur_redir)
{
	int		file_fd;
	t_error	err;

	err = redir__open_file(&file_fd, cur_redir->filename,
		O_WRONLY | O_APPEND | O_CREAT);
	if (is_error(err))
	{
		return (err);
	}
	err = exec__add_tracker(first_fd, file_fd, tracker_lst);
	close(file_fd);
	if (is_error(err))
	{
		return (errorf("redirecting %s to %d: %s",
			cur_redir->filename, first_fd, err.msg));
	}
	return (error_none());
}
