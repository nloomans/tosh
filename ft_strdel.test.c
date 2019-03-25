/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdel.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:30:22 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/25 18:40:29 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <stdlib.h>
#include <string.h>

TEST(test_basic, void strdelf(char **as))
{
	PRINT();
	char *mem = malloc(5);
	strdelf(&mem);
	assert(mem == NULL);
}

TEST(test_null, void strdelf(char **as))
{
	PRINT();
	strdelf(NULL);
}

int		main(void)
{
	RUN(test_basic, ft_strdel);
	RUN(test_null, ft_strdel);
}
