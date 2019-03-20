/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 11:46:13 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/20 11:54:51 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

#include <libft.h>
#include <string.h>

int		main(void)
{
	char src[4] = "foo";
	char dst[4];

	ft_strcpy(dst, src);
	assert(strcmp(src, dst) == 0);
}
