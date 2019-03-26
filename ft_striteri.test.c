/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.test.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 17:49:53 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/26 18:18:00 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>

void	f(unsigned int pos, char *c)
{
	static unsigned int i = 0;
	
	assert(pos == i);
	*c = i + '0';
	i++;
}

TEST(test_basic, void striterif(char *s, void f(unsigned int, char *)))
{
	PRINT();
	char str[] = "foo";
	char goal[] = "012";
	striterif(str, f);
	assert(strcmp(str, goal) == 0);
}

TEST(test_empty_str, void striterif(char *s, void f(unsigned int, char *)))
{
	PRINT();
	striterif("", NULL);
}

int		main(void)
{
	RUN(test_basic, ft_striteri);
	RUN(test_empty_str, ft_striteri);
}
