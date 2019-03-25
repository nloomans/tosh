/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.test.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:34:10 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 12:22:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_basic, void bzerof(void *b, size_t len))
{
	PRINT();
	char dst[10];
	char dst_goal[] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
	
	bzerof(dst, sizeof(dst));
	assert(memcmp(dst, dst_goal, sizeof(dst)) == 0);
}

int		main(void)
{
	RUN2(test_basic, ft_bzero, bzero);
}
