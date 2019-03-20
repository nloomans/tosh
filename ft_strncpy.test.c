/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:25:23 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/20 13:41:21 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "test_macros.h"

TEST(test_more_room, char *strncpyf(char *dst, const char *src, size_t len))
{
	PRINT();
	char dst[6];
	char dst_goal[6] = { 'a', 'b', 'c', '\0', '\0', '\0'};
	char src[] = "abc";
	char *dst_ptr = strncpyf(dst, src, sizeof(dst));
	assert(dst_ptr == dst);
	assert(strcmp(src, dst) == 0);
	assert(memcmp(dst_goal, dst, sizeof(dst)) == 0);
}

TEST(test_less_room, char *strncpyf(char *dst, const char *src, size_t len))
{
	PRINT();
	char dst[3];
	char dst_goal[3] = { 'a', 'b', 'c' };
	char src[] = "abcdef";
	char *dst_ptr = strncpyf(dst, src, sizeof(dst));
	assert(dst_ptr == dst);
	assert(memcmp(dst_goal, dst, sizeof(dst)) == 0);
}

TEST(test_no_room, char *strncpyf(char *dst, const char *src, size_t len))
{
	PRINT();
	char dst[] = "keep_same";
	char src[] = "abcdef";
	char *dst_ptr = strncpyf(dst, src, 0);
	assert(dst_ptr == dst);
	assert(memcmp("keep_same", dst, sizeof(dst)) == 0);
}

int		main(void)
{
	RUN(test_more_room,		ft_strncpy, strncpy);
	RUN(test_less_room,		ft_strncpy, strncpy);
	RUN(test_no_room,		ft_strncpy, strncpy);
}
