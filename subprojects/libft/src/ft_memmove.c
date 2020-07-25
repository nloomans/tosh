/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 18:25:40 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/28 20:19:18 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns 0 of there is no overlap between dst and src, of if there is safe
** overlap. (safe being any overlap which is safe to copy when using a left to
** right copy algorithm.) Returns 1 if there is unsafe overlap.
**
** If src and dst are equal, our return value doesn't matter. Right now we mark
** it as safe.
**
** This comparison works because void* are incremented in steps of 1. Unlike
** int* which are incremented in steps of 4[0].
**
** Reference:
**  safe overlap
**
**   foo_@@hello
**       ^----#
**       dst
**         ^----#
**         src
**
**  unsafe overlap:
**
**   foo_hello@@
**       ^----#
**       src
**         ^----#
**         dst
**
** [0]: https://boredzo.org/pointers/#arithmetic
*/

static int	has_unsafe_overlap(const void *dst, const void *src, size_t len)
{
	const char	*c_src;
	const char	*c_dst;

	c_src = src;
	c_dst = dst;
	return (c_src < c_dst && c_dst <= c_src + len);
}

static void	*memcpy_reverse(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	str_index;

	i = 0;
	while (i < len)
	{
		str_index = len - i - 1;
		((unsigned char *)dst)[str_index] = ((unsigned char*)src)[str_index];
		i++;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (has_unsafe_overlap(dst, src, len))
		return (memcpy_reverse(dst, src, len));
	else
		return (ft_memcpy(dst, src, len));
}
