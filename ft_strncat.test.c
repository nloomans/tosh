/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 15:47:52 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/21 16:40:41 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_basic, char *strncatf(char *s1, const char *s2, size_t n))
{
	PRINT();
	char src[] = 		"foo";
	char dst[] =		"bar\0test!";
	char dst_goal[] =	"barfoo\0t!";

	assert(strncatf(dst, src, 3) == dst);
	assert(memcmp(dst, dst_goal, sizeof(dst_goal)) == 0);
}

TEST(test_less_space, char *strncatf(char *s1, const char *s2, size_t n))
{
	PRINT();
	char src[] = 		"foobar";
	char dst[] =		"bar\0test!";
	char dst_goal[] =	"barfoo\0t!";

	assert(strncatf(dst, src, 3) == dst);
	assert(memcmp(dst, dst_goal, sizeof(dst_goal)) == 0);
}


TEST(test_more_space, char *strncatf(char *s1, const char *s2, size_t n))
{
	PRINT();
	char src[] = 		"foo";
	char dst[] =		"bar\0test!";
	char dst_goal[] =	"barfoo\0t!";

	assert(strncatf(dst, src, 6) == dst);
	assert(memcmp(dst, dst_goal, sizeof(dst_goal)) == 0);

}

int		main(void)
{
	RUN(test_basic, ft_strncat, strncat);
	RUN(test_less_space, ft_strncat, strncat);
	RUN(test_more_space, ft_strncat, strncat);
}
