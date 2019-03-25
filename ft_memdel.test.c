/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdel.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:30:22 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 18:34:02 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <stdlib.h>
#include <string.h>

TEST(test_basic, void memdelf(void **ap))
{
	PRINT();
	void *mem = malloc(5);
	memdelf(&mem);
	assert(mem == NULL);
}

TEST(test_null, void memdelf(void **ap))
{
	PRINT();
	memdelf(NULL);
}

int		main(void)
{
	RUN(test_basic, ft_memdel);
	RUN(test_null, ft_memdel);
}
