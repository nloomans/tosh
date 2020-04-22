/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tosh - 21 Shell                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosh <tosh@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by tosh          #+#    #+#                 */
/*   Updated: 1970/01/01 99:99:99 by tosh          ########   odam.nl         */
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
