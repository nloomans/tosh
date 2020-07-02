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
				const struct s_io_file *const current_redirect)
{
	int		file_fd;
	t_error	err;

	file_fd = open(current_redirect->filename, O_RDONLY);
	if (file_fd == -1)
	{
		return (errorf("could not open: %s", current_redirect->filename));
	}
	err = exec__add_tracker(first_fd, file_fd, tracker_lst);
	close(file_fd);
	if (is_error(err))
	{
		return (errorf("redirecting %s to %d: %s",
			current_redirect->filename, first_fd, err.msg));
	}
	return (error_none());
}

// t_error		redirect_in_and(t_list_meta *const tracker_lst,
// 				const int first_fd,
// 				const struct s_io_file *const current_redirect)
// {

// }

t_error		redirect_out(t_list_meta *const tracker_lst,
				const int first_fd,
				const struct s_io_file *const current_redirect)
{
	int		file_fd;
	t_error	err;

	file_fd = open(current_redirect->filename, O_WRONLY | O_TRUNC | O_CREAT);
	if (file_fd == -1)
	{
		return (errorf("could not open: %s", current_redirect->filename));
	}
	err = exec__add_tracker(first_fd, file_fd, tracker_lst);
	close(file_fd);
	if (is_error(err))
	{
		return (errorf("redirecting %s to %d: %s",
			current_redirect->filename, first_fd, err.msg));
	}
	return (error_none());
}

t_error		redirect_out_append(t_list_meta *const tracker_lst,
				const int first_fd,
				const struct s_io_file *const current_redirect)
{
	int		file_fd;
	t_error	err;

	file_fd = open(current_redirect->filename, O_WRONLY | O_APPEND | O_CREAT);
	if (file_fd == -1)
	{
		return (errorf("could not open: %s", current_redirect->filename));
	}
	err = exec__add_tracker(first_fd, file_fd, tracker_lst);
	close(file_fd);
	if (is_error(err))
	{
		return (errorf("redirecting %s to %d: %s",
			current_redirect->filename, first_fd, err.msg));
	}
	return (error_none());
}

// t_error		redirect_out_and(t_list_meta *const tracker_lst,
// 				const int first_fd,
// 				const struct s_io_file *const current_redirect)
// {

// }
