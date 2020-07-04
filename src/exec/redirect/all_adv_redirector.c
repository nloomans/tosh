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

static int	parse_num(char const *num_str)
{
	while (*num_str != '\0')
	{
		if (ft_isdigit(*num_str))
		{
			return (-1);
		}
		num_str++;
	}
	return (ft_atoi(num_str));
}

t_error		redirect_in_and(t_list_meta *const tracker_lst,
				const int first_fd,
				const struct s_io_file *const cur_redir)
{
	int		redir_fd;
	t_error	err;

	redir_fd = parse_num(cur_redir->filename + 1);
	if (redir_fd == -1)
	{
		ft_memmove(cur_redir->filename, cur_redir->filename + 1,
			ft_strlen(cur_redir->filename));//maybe a terrible idea
		return (redirect_in(tracker_lst, first_fd, cur_redir));
	}
	if (exec__is_protected_fd(redir_fd) == true)
	{
		return (errorf("%d is a protected fd", redir_fd));
	}
	err = exec__add_tracker(first_fd, redir_fd, tracker_lst);
	if (is_error(err))
	{
		return (errorf("redirecting %s to %d: %s",
			cur_redir->filename, first_fd, err.msg));
	}
	return (error_none());
}



// t_error		redirect_out_and(t_list_meta *const tracker_lst,
// 				const int first_fd,
// 				const struct s_io_file *const cur_redir)
// {

// }
