/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: ivan-tey <ivan-tey@student.codam.nl>          +:+                    */
/*       nloomans <nloomans@student.codam.nl>         +#+                     */
/*       aholster <aholster@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <ft_printf.h>
#include <assert.h>
#include "pub.h"
#include "priv.h"

/*
** u7 ("User string #7") requests the cursor position to be send on xterm
** terminals. This might break very obscure terminal emulators...
*/

t_error				term_getcursor(struct s_term_pos *out)
{
	char				response[16];
	ptrdiff_t			offset;
	int					n;

	ft_memset(&response, '\0', sizeof(response));
	term__send("u7");
	n = read(STDIN_FILENO, &response, sizeof(response) - 1);
	if (strncmp(response, "\033[", 2) != 0)
		return (errorf("expected terminal response to start with \\033["));
	out->row = ft_atoi(response + 2);
	offset = ft_strdropwhile(response + 2, ft_isdigit) - response;
	if (response[offset] != ';')
		return (errorf("expected terminal response be seperated with ;"));
	out->column = ft_atoi(response + offset);
	offset = ft_strdropwhile(response + offset + 1, ft_isdigit) - response;
	if (response[offset] != 'R')
		return (errorf("expected terminal response to end with R"));
	if (n != offset + 1)
		return (errorf("unexpected extra data at end of terminal response"));
	return (ERROR_NONE);
}
