/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:34:10 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/21 18:50:24 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_basic, char *strchrf(const char *s, int c))
{
	PRINT();
	char *str = "abcde";
	assert(strchrf(str, 'c') == str + 2);
}

TEST(test_find_null, char *strchrf(const char *s, int c))
{
	PRINT();
	char *str = "abcde";
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
	RUN(test_basic, ft_strchr, strchr);
	RUN(test_find_null, ft_strchr, strchr);
	RUN(test_not_found, ft_strchr, strchr);
}
