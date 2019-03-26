/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclr.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 17:39:32 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/26 17:48:55 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>

TEST(test_basic, void strclrf(char *s))
{
	PRINT();
	char str[] = "foo";
	char goal[] = { 0, 0, 0, 0 };
	strclrf(str);
	assert(memcmp(str, goal, 4) == 0);
}

TEST(test_0_len, void strclrf(char *s))
{
	PRINT();
	char str[] = "";
	char goal[] = { 0 };
	strclrf(str);
	assert(memcmp(str, goal, 1) == 0);
}

int		main(void)
{
	RUN(test_basic, ft_strclr);
	RUN(test_0_len, ft_strclr);
}
