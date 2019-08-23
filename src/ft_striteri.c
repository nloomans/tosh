/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 17:52:03 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/26 18:12:38 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void f(unsigned int, char *))
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
