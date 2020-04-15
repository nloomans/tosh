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

#include <stdlib.h>

#include "lexer.h"

void	lexer_clear(t_list_meta *const all_token)
{
	struct s_token	*temp;
	t_list_conn		*iter;

	while (all_token->first != NULL)
	{
		iter = all_token->first;
		ft_list_unlink(all_token, iter);
		temp = unpack_token(iter);
		ft_strdel(&temp->string);
		ft_bzero(temp, sizeof(*temp));
		free(temp);
	}
}
