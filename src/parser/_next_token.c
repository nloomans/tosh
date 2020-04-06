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
