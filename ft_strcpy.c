/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 11:38:10 by nloomans      #+#    #+#                 */
/*   Updated: 2019/03/20 11:51:15 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
			break ;
		i++;
	}
	return (dst);
}
