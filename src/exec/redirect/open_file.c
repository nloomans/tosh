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

t_error		redir__open_file(int *const afd,
				const char *const filename,
				const int oflags)
{
	if (access(filename, F_OK) == -1 && (oflags & O_CREAT) == 0)
	{
		return (errorf("no such file or directory: %s", filename));
	}
	*afd = open(filename, oflags, 0644);
	if (*afd == -1)
	{
		return (errorf("could not open: %s", filename));
	}
	return (error_none());
}
