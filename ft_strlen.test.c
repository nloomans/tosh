/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 18:02:12 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/19 18:34:45 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

#include <libft.h>
#include <string.h>

int		main(void)
{
	char *tests[] = {
		"foo",
		"aqwesdftgyhujkl",
		"hello\0world",
		""
	};

	for (unsigned int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
	{
		printf("testing \"%s\"\n", tests[i]);
		assert(strlen(tests[i]) == ft_strlen(tests[i]));
	}
	return (0);
}
