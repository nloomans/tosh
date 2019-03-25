/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.test.c                                   :+:    :+:            */
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

TEST(test_basic, char *strchrf(const char *s, int c))
{
	PRINT();
	char *str = "abccdec";
	assert(strchrf(str, 'c') == str + 2);
}

TEST(test_find_null, char *strchrf(const char *s, int c))
{
	PRINT();
	char *str = "abcde\0fg";
	assert(strchrf(str, '\0') == str + 5);
}

TEST(test_not_found, char *strchrf(const char *s, int c))
{
	PRINT();
	char *str = "abcde";
	assert(strchrf(str, 'f') == NULL);
}

int		main(void)
{
	RUN2(test_basic, ft_strchr, strchr);
	RUN2(test_find_null, ft_strchr, strchr);
	RUN2(test_not_found, ft_strchr, strchr);
}
