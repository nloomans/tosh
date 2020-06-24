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

#include <termios.h>
#include <unistd.h>

#include "private.h"
#include "../error/error.h"

t_error		term_restore(t_term **out)
{
	struct termios original;

	original = (*out)->original_termios;
	*out = NULL;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &original) == -1)
		return (errorf("tcsetattr failed"));
	return (error_none());
}
