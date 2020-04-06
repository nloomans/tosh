/* ************************************************************************** */
/*                                                                            */
/*   tosh - 21 Shell                                      ::::::::            */
/*                                                      :+:    :+:            */
/*   By: aholster <aholster@student.codam.nl>          +:+                    */
/*       ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*       nloomans <nloomans@student.codam.nl>        +#+                      */
/*                                                 #+#    #+#                 */
/*   License: GPLv3                                ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf.h>
#include "../error/error.h"
#include "private.h"

void	parser__errorf(t_parser *const p, const char *const fmt, ...)
{
	va_list	vlist;
	ssize_t	ret;

	if (is_error(p->error))
		return ;
	va_start(vlist, fmt);
	// TODO: Update ft_*printf to take a const for fmt.
	ret = ft_vsnprintf(p->error.msg, sizeof(p->error.msg), (char *)fmt, vlist);
	va_end(vlist);
	if (ret == -1)
	{
		p->error = ((t_error){
			.msg = "an error occurred during the generation of this error" });
	}
}
