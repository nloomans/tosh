/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdropwhile.test.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:17:58 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/20 18:31:09 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>
#include "test_macros.h"

TEST(test_basic, char *strdropwhilef(const char *str, int should_skip(int c)))
{
	PRINT();
	char *str = "  \t  foo";
	char *goal = str + 5;
	assert(strdropwhilef(str, isspace) == goal);
}

static int isanything(int c)
{
	(void)c;
	return (1);
}

TEST(test_no_end, char *strdropwhilef(const char *str, int should_skip(int c)))
{
	PRINT();
	char *str = "  \t  ";
	char *goal = str + 5;
	assert(strdropwhilef(str, isanything) == goal);
}

int		main(void)
{
	test_basic("libft", ft_strdropwhile);
	test_no_end("libft", ft_strdropwhile);
}