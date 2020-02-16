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

#include <term.h>
#include "pub.h"

void	term_init(const char *term_env)
{
	tgetent(NULL, term_env);
}
