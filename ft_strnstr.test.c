/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 15:48:47 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/23 15:28:01 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(	test_basic,
		char *strnstrf(const char *haystack, const char *needle, size_t len))
{
	PRINT();
	char *haystack = "testing foo testing foo";
	assert(strnstrf(haystack, "foo", strlen(haystack)) == haystack + 8);
}

TEST(	test_empty_needle,
		char *strnstrf(const char *haystack, const char *needle, size_t len))
{
	PRINT();
	char *haystack = "testing foo testing foo";
	assert(strnstrf(haystack, "", strlen(haystack)) == haystack);
}

TEST(	test_len,
		char *strnstrf(const char *haystack, const char *needle, size_t len))
{
	PRINT();
	char *haystack = "testing foo testing foo";
	assert(strnstrf(haystack, "foo", 10) == NULL);
	assert(strnstrf(haystack, "foo", 7 /* testing */ + 1 /* " " */ + 3 /* foo */) == haystack + 8);
}


int		main(void)
{
	RUN(test_basic, ft_strnstr, strnstr);
	RUN(test_empty_needle, ft_strnstr, strnstr);
	RUN(test_len, ft_strnstr, strnstr);
}
