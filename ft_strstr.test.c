/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.test.c                                   :+:    :+:            */
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

TEST(test_basic, char *strstrf(const char *haystack, const char *needle))
{
	PRINT();
	char *haystack = "testing foo testing foo";
	assert(strstrf(haystack, "foo") == haystack + 8);
}

TEST(test_empty_needle, char *strstrf(const char *haystack, const char *needle))
{
	PRINT();
	char *haystack = "testing foo testing foo";
	assert(strstrf(haystack, "") == haystack);
}

int		main(void)
{
	RUN2(test_basic, ft_strstr, strstr);
	RUN2(test_empty_needle, ft_strstr, strstr);
}
