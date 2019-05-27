#include <assert.h>
#include <stddef.h>
#include <libft.h>
#include "token.h"
#include "parser.h"

# include <stdio.h>

static int			is_conversion_specification(const char *stream)
{
	assert(stream != NULL);
	return (*stream == '%');
}

static int			is_color_specification(const char *stream)
{
	assert(stream != NULL);
	return (stream[0] == '%' && stream[1] == '{');
}

static int			parse_color_specification(t_token *dest, char **stream)
{
	assert(dest != NULL && stream != NULL && *stream != NULL);
	assert(is_color_specification(*stream));

	(*stream) += 2;
	dest->type = E_COLOR;
	dest->s_value = *stream;
	while (**stream != '}' && **stream != '\0')
		(*stream)++;
	dest->s_length = *stream - dest->s_value;
	if (**stream == '\0')
		return (-1);
	else
		(*stream)++;
	return (**stream != '\0');
}

static int			parse_flags(char **stream)
{
	t_flags		flags = 0;

	assert(stream != NULL && *stream != NULL);
	while (ft_strchr("# 0+-", **stream))
	{
		if (**stream == '#')
			flags |= FLAGS_HASH;
		else if (**stream == ' ')
			flags |= FLAGS_SPACE;
		else if (**stream == '0')
			flags |= FLAGS_ZEROPAD;
		else if (**stream == '+')
			flags |= FLAGS_PLUS;
		else if (**stream == '-')
			flags |= FLAGS_LEFTALIGN;
		else
			assert(0);
		(*stream)++;
	}
	return (flags);
}

static int			parse_width(char **stream)
{
	assert(stream != NULL && *stream != NULL);
	return (parse_atoi_wildcard(stream));
}

static int			parse_precision(t_flags *flags, char **stream)
{
	assert(flags != NULL && stream != NULL && *stream != NULL);
	if (**stream != '.')
		return (0);
	(*stream)++;
	*flags |= FLAGS_PRECISION;
	return (parse_atoi_wildcard(stream));
}

static t_size		parse_size(char **stream)
{
	assert(stream != NULL && *stream != NULL);
	if (**stream == 'h')
	{
		(*stream)++;
		if (**stream == 'h')
		{
			(*stream)++;
			return (E_HH);
		}
		else
			return (E_H);
	}
	else if (**stream == 'l')
	{
		(*stream)++;
		if (**stream == 'l')
		{
			(*stream)++;
			return (E_LL);
		}
		else
			return (E_L);
	}
	else
		return (E_N);
}

static const t_char2descriptor map_char2descriptor[] = {
	{ 'd', E_INT },
	{ 'i', E_INT },
	{ 's', E_STR },
	{ 'o', E_OCT },
	{ 'u', E_UNS },
	{ 'p', E_PTR },
	{ 'c', E_CHR },
	{ '%', E_PERCENT },
	{ 'm', E_MEMORY },
	{ 'x', E_HEX },
	{ 'f', E_FLOAT },
};

static t_descriptor	parse_conversion_specifier(t_flags *flags, char **stream)
{
	char	c;
	size_t	i;

	assert(flags != NULL && stream != NULL && *stream != NULL);
	c = **stream;
	(*stream)++;
	if (c == '\0')
		return (E_INVALID);
	if (c >= 'A' && c <= 'Z')
	{
		*flags |= FLAGS_CAPITAL;
		c = ft_tolower(c);
	}
	i = 0;
	while (i < sizeof(map_char2descriptor) / sizeof(t_char2descriptor))
	{
		if (map_char2descriptor[i].c == c)
			return (map_char2descriptor[i].descriptor);
		i++;
	}
	return (E_INVALID);
}

static int			parse_conversion_specification(t_token *dest, char **stream)
{
	assert(dest != NULL && stream != NULL && *stream != NULL);
	assert(is_conversion_specification(*stream));
	(*stream)++;
	dest->flags = parse_flags(stream);
	dest->width = parse_width(stream);
	dest->precision = parse_precision(&dest->flags, stream);
	dest->size = parse_size(stream);
	dest->type = parse_conversion_specifier(&dest->flags, stream);
	if (dest->type == E_INVALID)
		return (-1);
	return (**stream != '\0');
}

static int			parse_string_literal(t_token *dest, char **stream)
{
	assert(dest != NULL && stream != NULL && *stream != NULL);
	assert(!is_conversion_specification(*stream));

	dest->type = E_TXT;
	dest->s_value = *stream;
	while (!is_conversion_specification(*stream) && **stream != '\0')
		(*stream)++;
	dest->s_length = *stream - dest->s_value;
	return (**stream != '\0');
}

int		parse_token(t_token *dest, char **stream)
{
	assert(dest != NULL && stream != NULL && *stream != NULL);
	ft_memset(dest, '\0', sizeof(t_token));
	if (is_color_specification(*stream))
		return (parse_color_specification(dest, stream));
	else if (is_conversion_specification(*stream))
		return (parse_conversion_specification(dest, stream));
	else
		return (parse_string_literal(dest, stream));
}
