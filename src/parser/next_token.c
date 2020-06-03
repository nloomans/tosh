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

#include <assert.h>
#include "private.h"

struct s_token			*parser__next_token(t_parser *const p)
{
	struct s_token *ret;

	assert(p->cursor != NULL);
	ret = unpack_token(p->cursor);
	p->cursor = p->cursor->next;
	return (ret);
}
