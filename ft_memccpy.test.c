/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:50:58 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/23 17:06:53 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_basic, void *memccpyf(void *dst, const void *src, int c, size_t n))
{
	PRINT();
	char src[] = "abcdnot__copied";
	char dst[] = "@@@@not_touched";
	char dst_goal[] = "abcdnot_touched";

	assert(memccpyf(dst, src, 'd', sizeof(src)) == dst + 4 /* abcd */);	
	assert(memcmp(dst, dst_goal, sizeof(dst)) == 0);
}

int		main(void)
{
	RUN(test_basic, ft_memccpy, memccpy);
}
