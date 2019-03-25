/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 11:40:00 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 12:22:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_basic, void *memchrf(const void *s, int c, size_t n))
{
	PRINT();
	char str[] = "abccdec";
	assert(memchrf(str, 'c', sizeof(str)) == str + 2);
}

TEST(test_find_null, void *memchrf(const void *s, int c, size_t n))
{
	PRINT();
	char str[] = "abcde\0fg";
	assert(memchrf(str, '\0', sizeof(str)) == str + 5);
}

TEST(test_not_found, void *memchrf(const void *s, int c, size_t n))
{
	PRINT();
	char str[] = "abcde";
	assert(memchrf(str, 'f', sizeof(str)) == NULL);
}

TEST(test_n_0, void *memchrf(const void *s, int c, size_t n))
{
	PRINT();
	char str[] = "abcde";
	assert(memchrf(str, 'a', 0) == NULL);
}

int		main(void)
{
	RUN2(test_basic, ft_memchr, memchr);
	RUN2(test_find_null, ft_memchr, memchr);
	RUN2(test_not_found, ft_memchr, memchr);
	RUN2(test_n_0, ft_memchr, memchr);
}
