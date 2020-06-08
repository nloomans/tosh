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

#include <sys/ioctl.h>
#include <unistd.h>
#include <libft.h>

#include "term.h"

int		term_getsize(struct s_term_pos *out)
{
	struct winsize	w;

	ft_memset(&w, '\0', sizeof(w));
	if (ioctl(STDERR_FILENO, TIOCGWINSZ, &w) == -1)
	{
		return (-1);
	}
	out->row = w.ws_row;
	out->column = w.ws_col;
	return (0);
}
