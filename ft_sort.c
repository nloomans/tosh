/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 18:56:33 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/30 18:56:45 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			ft_sort(int ac, void **av, int cmpf())
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = i;
		while (j > 0 && cmpf(av[j - 1], av[j]) > 0)
		{
			ft_swap((void**)&av[j - 1], (void**)&av[j]);
			j--;
		}
		i++;
	}
}
