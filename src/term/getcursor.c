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

#include <libft.h>
#include <unistd.h>

#include "private.h"

/*
** u7 ("User string #7") requests the cursor position to be send on xterm
** terminals. This might break very obscure terminal emulators...
*/

t_error				term__getcursor(struct s_term_pos *out)
{
	char				response[16];
	ptrdiff_t			offset;
	int					n;

	ft_memset(&response, '\0', sizeof(response));
	term__send("u7");
	n = read(STDIN_FILENO, &response, sizeof(response) - 1);
	if (ft_strncmp(response, "\033[", 2) != 0)
		return (errorf("expected terminal response to start with \\033["));
	out->row = ft_atoi(response + 2) - 1;
	offset = ft_strdropwhile(response + 2, ft_isdigit) - response;
	if (response[offset] != ';')
		return (errorf("expected terminal response be seperated with ;"));
	out->column = ft_atoi(response + offset + 1) - 1;
	offset = ft_strdropwhile(response + offset + 1, ft_isdigit) - response;
	if (response[offset] != 'R')
		return (errorf("expected terminal response to end with R"));
	if (n != offset + 1)
		return (errorf("unexpected extra data at end of terminal response"));
	return (error_none());
}
