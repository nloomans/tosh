/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 17:49:53 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/26 18:17:51 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>

void	f(char *c)
{
	static char i = '0';
	
	*c = i;
	i++;
}

TEST(test_basic, void striterf(char *s, void f(char *)))
{
	PRINT();
	char str[] = "foo";
	char goal[] = "012";
	striterf(str, f);
	assert(strcmp(str, goal) == 0);
}

TEST(test_empty_str, void striterf(char *s, void f(char *)))
{
	PRINT();
	striterf("", NULL);
}

int		main(void)
{
	RUN(test_basic, ft_striter);
	RUN(test_empty_str, ft_striter);
}
