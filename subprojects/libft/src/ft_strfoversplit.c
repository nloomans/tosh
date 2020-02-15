/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:06:22 by nloomans       #+#    #+#                */
/*   Updated: 2019/03/30 18:03:38 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(const char *s, int should_split(int c))
{
	if (s[0] == '\0')
		return (0);
	if (!should_split(s[0]) && (should_split(s[1]) || s[1] == '\0'))
		return (word_count(s + 1, should_split) + 1);
	return (word_count(s + 1, should_split));
}

static int		char_index(const char *s, int should_split(int c))
{
	const char *char_ptr;

	char_ptr = s;
	while (*char_ptr != '\0' && !should_split(*char_ptr))
		char_ptr++;
	if (char_ptr == NULL)
		char_ptr = (char *)s + ft_strlen(s);
	return (char_ptr - s);
}

static void		ft_strsplit_c(char **words, const char *s,
				int should_split(int c))
{
	int		section_len;

	if (*s == '\0')
		return ;
	if (should_split(*s))
	{
		ft_strsplit_c(words, s + 1, should_split);
		return ;
	}
	section_len = char_index(s, should_split);
	*words = ft_strsub(s, 0, section_len);
	ft_strsplit_c(words + 1, s + section_len, should_split);
}

char			**ft_strfoversplit(const char *s, int should_split(int c))
{
	char	**words;

	words = (char **)ft_memalloc(sizeof(*words) *
		(word_count(s, should_split) + 1));
	if (words == NULL)
		return (NULL);
	ft_strsplit_c(words, s, should_split);
	return (words);
}
