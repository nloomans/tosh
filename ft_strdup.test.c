/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 11:56:08 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/20 12:10:53 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char	*tests[] = {
		"foo",
		"bar",
		"",
		"foo\0bar"
	};

	for (size_t i = 0; i < sizeof(tests) / sizeof(*tests); i++)
	{
		printf("testing \"%s\"\n", tests[i]);
		char *dup = ft_strdup(tests[i]);
		assert(strcmp(dup, tests[i]) == 0);
		free(dup);
	}
}
