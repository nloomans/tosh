/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.test.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:22:34 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 18:26:28 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>

TEST(test_basic, void *memallocf(size_t size))
{
	PRINT();
	void *dst = memallocf(5);
	char dst_goal[] = { 0, 0, 0, 0, 0 };
	assert(memcmp(dst, dst_goal, sizeof(dst_goal)) == 0);
}

int		main(void)
{
	RUN(test_basic, ft_memalloc);
}
