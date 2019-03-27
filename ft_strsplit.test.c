/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.test.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:27:50 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/27 19:30:03 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_macros.h"
#include <libft.h>
#include <string.h>

TEST(test_basic, char **strsplitf(const char *s, char c))
{
	PRINT();
	char **res = strsplitf("*hello*fellow***students*", '*');
	printf("res[0]: %s\n", res[0]);
	assert(strcmp(res[0], "hello") == 0);
	assert(strcmp(res[1], "fellow") == 0);
	assert(strcmp(res[2], "students") == 0);
	assert(res[3] == NULL);
}

TEST(test_empty, char **strsplitf(const char *s, char c))
{
	PRINT();
	char **res = strsplitf("", '*');
	assert(res[0] == NULL);
}

TEST(test_no_words, char **strsplitf(const char *s, char c))
{
	PRINT();
	char **res = strsplitf("**", '*');
	assert(res[0] == NULL);
}

TEST(test_only_word, char **strsplitf(const char *s, char c))
{
	PRINT();
	char **res = strsplitf("hello", '*');
	assert(strcmp(res[0], "hello") == 0);
	assert(res[1] == NULL);
}


int		main(void)
{
	RUN(test_basic, ft_strsplit);
	RUN(test_empty, ft_strsplit);
	RUN(test_no_words, ft_strsplit);
	RUN(test_only_word, ft_strsplit);
}
