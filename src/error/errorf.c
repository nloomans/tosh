/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   TOSH                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "error.h"

t_error	errorf(char *fmt, ...)
{
	va_list	vlist;
	ssize_t	ret;
	t_error	dest;

	va_start(vlist, fmt);
	ret = ft_vsnprintf(dest.msg, sizeof(dest.msg), fmt, vlist);
	va_end(vlist);
	if (ret == -1)
	{
		return ((t_error){
			.msg = "an error occurred during the generation of this error" });
	}
	return (dest);
}
