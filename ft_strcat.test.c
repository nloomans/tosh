/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 13:01:59 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 12:22:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_basic, char *strcatf(char *s1, const char *s2))
{
	PRINT();
	char src[] = 		"foo";
	char dst[] =		"bar\0test!";
	char dst_goal[] =	"barfoo\0t!";

	assert(strcatf(dst, src) == dst);
	assert(memcmp(dst, dst_goal, sizeof(dst_goal)) == 0);

}

int		main(void)
{
	RUN2(test_basic, ft_strcat, strcat);
}
