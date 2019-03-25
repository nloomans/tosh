/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 17:20:33 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 12:22:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_basic, size_t strlcatf(char *dst, const char *src, size_t size))
{
	PRINT();
	char dst[] = "hello\0@@@@@not_touched";
	char dst_goal[] = "helloworld\0not_touched";
	char src[] = "world";
	assert(strlcatf(dst, src, sizeof(dst)) == 10);
	assert(memcmp(dst, dst_goal, sizeof(dst)) == 0);
}

TEST(test_src_too_long, size_t strlcatf(char *dst, const char *src, size_t size))
{
	PRINT();
	char dst[] = "hello\0@@@@@not_touched";
	char dst_goal[] = "helloworld\0not_touched";
	char src[] = "worldextra";
	assert(strlcatf(dst, src, 5 /* hello */ + 5 /* world */ + 1 /* \0 */) == 15);
	assert(memcmp(dst, dst_goal, sizeof(dst)) == 0);
}

TEST(test_dst_full, size_t strlcatf(char *dst, const char *src, size_t size))
{
	PRINT();
	char dst[] = "hello\0not_touched";
	char dst_goal[] = "hello\0not_touched";
	char src[] = "world";
	assert(strlcatf(dst, src, 5 /* hello */ + 1 /* \0 */) == 10);
	assert(memcmp(dst, dst_goal, sizeof(dst)) == 0);
}

TEST(test_dst_invalid, size_t strlcatf(char *dst, const char *src, size_t size))
{
	PRINT();
	char dst[] = "hellonot_touched";
	char dst_goal[] = "hellonot_touched";
	char src[] = "world";
	assert(strlcatf(dst, src, 5 /* hello */) == 10);
	assert(memcmp(dst, dst_goal, sizeof(dst)) == 0);
}

int		main(void)
{
	RUN2(test_basic, ft_strlcat, strlcat);
	RUN2(test_src_too_long, ft_strlcat, strlcat);
	RUN2(test_dst_full, ft_strlcat, strlcat);
	RUN2(test_dst_invalid, ft_strlcat, strlcat);
}
