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

#include <stdarg.h>
#include <ft_printf.h>
#include "../error/error.h"
#include "private.h"

/*
** TODO: Update ft_*printf to take a const for fmt.
*/

void	parser__errorf(t_parser *const p, const char *const fmt, ...)
{
	va_list	vlist;
	ssize_t	ret;

	if (is_error(p->error))
		return ;
	va_start(vlist, fmt);
	ret = ft_vsnprintf(p->error.msg, sizeof(p->error.msg), (char *)fmt, vlist);
	va_end(vlist);
	if (ret == -1)
	{
		p->error = ((t_error){
			.msg = "an error occurred during the generation of this error" });
	}
}
