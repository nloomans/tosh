/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 17:49:53 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/26 18:24:00 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>

char	f(char c)
{
	static unsigned int i = 0;
	
	assert(c == (char)i + 'a');
	return (i++ + '0');
}

TEST(test_basic, char *strmapf(const char *s, char f(char)))
{
	PRINT();
	char src[] = "abc";
	char *dst;
	char goal[] = "012";
	dst = strmapf(src, f);
	assert(strcmp(dst, goal) == 0);
}

TEST(test_empty_str, char *strmapf(const char *s, char f(char)))
{
	PRINT();
	assert(strmapf("", NULL)[0] == '\0');
}

int		main(void)
{
	RUN(test_basic, ft_strmap);
	RUN(test_empty_str, ft_strmap);
}
