/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:34:10 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/21 19:13:23 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "test_macros.h"

TEST(test_basic, char *strrchrf(const char *s, int c))
{
	PRINT();
	char *str = "abccde";
	assert(strrchrf(str, 'c') == str + 3);
}

TEST(test_find_null, char *strrchrf(const char *s, int c))
{
	PRINT();
	char *str = "abcde\0fg";
	assert(strrchrf(str, '\0') == str + 5);
}

TEST(test_not_found, char *strrchrf(const char *s, int c))
{
	PRINT();
	char *str = "abcde";
	assert(strrchrf(str, 'f') == NULL);
}

int		main(void)
{
	RUN(test_basic, ft_strrchr, strrchr);
	RUN(test_find_null, ft_strrchr, strrchr);
	RUN(test_not_found, ft_strrchr, strrchr);
}
