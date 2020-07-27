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

#include <unistd.h>

#include "../private.h"

t_error		redirect_heredoc(t_list_meta *const tracker_lst,
				const int first_fd,
				const struct s_io_here *const heredoc)
{
	int			pip[2];
	t_error		err;

	if (pipe(pip) == -1)
	{
		return (errorf("failed to create pipe"));
	}
	write(pip[write_to], heredoc->contents, ft_strlen(heredoc->contents));
	close(pip[write_to]);
	err = exec__add_tracker(first_fd, pip[read_from], tracker_lst);
	if (is_error(err))
	{
		close(pip[read_from]);
	}
	return (err);
}
