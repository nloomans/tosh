#include <stdio.h>
#include "libft.h"

/*
** Free's a NULL-terminated array.
*/

void	ft_arraydel(void ***array, void delf(void **))
{
	size_t	i;

	i = 0;
	while ((*array)[i] != NULL)
	{
		delf(&(*array)[i]);
		i++;
	}
	ft_memdel((void **)array);
}
