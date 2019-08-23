/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 11:35:58 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/28 20:17:11 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calculate_strlen(int n)
{
	size_t	size;

	size = (n < 0 || n == 0) ? 1 : 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static char		digit_to_char(int n)
{
	return (n + '0');
}

char			*ft_itoa(int n)
{
	char	*dst;
	size_t	dst_len;
	size_t	i;

	dst_len = calculate_strlen(n);
	dst = ft_strnew(dst_len);
	i = 0;
	if (dst == NULL)
		return (NULL);
	if (n < 0)
		dst[0] = '-';
	else if (n == 0)
		dst[0] = '0';
	else
		n *= -1;
	while (n != 0)
	{
		dst[dst_len - i - 1] = digit_to_char(-(n % 10));
		n /= 10;
		i++;
	}
	return (dst);
}
