/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 17:49:53 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/26 18:26:17 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>

char	f(unsigned int pos, char c)
{
	static unsigned int i = 0;
	
	assert(pos == i);
	assert(c == (char)i + 'a');
	return (i++ + '0');
}

TEST(test_basic, char *strmapif(const char *s, char f(unsigned int, char)))
{
	PRINT();
	char src[] = "abc";
	char *dst;
	char goal[] = "012";
	dst = strmapif(src, f);
	assert(strcmp(dst, goal) == 0);
}

TEST(test_empty_str, char *strmapif(const char *s, char f(unsigned int, char)))
{
	PRINT();
	assert(strmapif("", NULL)[0] == '\0');
}

int		main(void)
{
	RUN(test_basic, ft_strmapi);
	RUN(test_empty_str, ft_strmapi);
}
