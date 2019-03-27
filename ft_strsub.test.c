/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 13:06:01 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/27 13:39:36 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>

TEST(test_basic, char *strsubf(const char *s, unsigned int start, size_t len))
{
	PRINT();
	assert(strcmp(strsubf("__foo__", 2, 3), "foo") == 0);
}

int		main(void)
{
	RUN(test_basic, ft_strsub);
}
