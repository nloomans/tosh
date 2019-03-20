/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 11:46:13 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/20 12:47:14 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char src[4] = "foo";
	char dst[4];

	ft_strcpy(dst, src);
	assert(memcmp(src, dst, 4) == 0);
}
