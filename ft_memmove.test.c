/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 18:35:25 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 12:22:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include "test_macros.h"

TEST(test_no_overlap, void *memmovef(void *dst, const void *src, size_t len))
{
	PRINT();
	char str[] = "foo_hello_bar_@@@@@";
	char *dst = strstr(str, "@@@@@");
	char *src = strstr(str, "hello");
	
	assert(memmovef(dst, src, 5) == dst);
	assert(memcmp(dst, src, 5) == 0);
}

TEST(test_safe_overlap, void *memmovef(void *dst, const void *src, size_t len))
{
	PRINT();
	char str[] = "foo_@hello";
	char *dst = strstr(str, "@hell");
	char *src = strstr(str, "hello");
	assert(memmovef(dst, src, 5) == dst);
	assert(memcmp(dst, "hello", 5) == 0);
}

TEST(test_unsafe_overlap, void *memmovef(void *dst, const void *src, size_t len))
{
	PRINT();
	char str[] = "foo_hello@";
	char *dst = strstr(str, "ello@");
	char *src = strstr(str, "hello");
	assert(memmovef(dst, src, 5) == dst);
	assert(memcmp(dst, "hello", 5) == 0);
}

int		main(void)
{
	RUN2(test_no_overlap, ft_memmove, memmove);
	RUN2(test_safe_overlap, ft_memmove, memmove);
	RUN2(test_unsafe_overlap, ft_memmove, memmove);
}
