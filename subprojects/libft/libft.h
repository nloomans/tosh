/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 18:27:26 by nloomans       #+#    #+#                */
/*   Updated: 2019/10/17 18:21:53 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdint.h>
# include <stdbool.h>

/*
** TYPES
*/

struct			s_ft_getopt
{
	char	*arg;
	int		index;
	int		group_index;
	char	opt;
	bool	illegal;
};

# define FT_GETOPT_DEFAULT (struct s_ft_getopt){0, 1, 1, 0, false}

/*
** PART 1 - LIBC FUNCTIONS
*/

/*
** string.h
*/

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(
					const char *haystack, const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** strings.h
*/

void			ft_bzero(void *s, size_t n);

/*
** stdlib.h
*/

int				ft_atoi(const char *str);

/*
** ctype.h
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** PART 2 - ADDITIONAL FUNCTIONS
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void f(char*));
void			ft_striteri(char *s, void f(unsigned int, char *));
char			*ft_strmap(const char *s, char f(char));
char			*ft_strmapi(const char *s, char f(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);
char			*ft_itoa(int n);

/*
** EXPANSION
*/

int				ft_isspace(int c);
char			*ft_strstrim(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strdropwhile(const char *str, int should_skip(int c));
void			ft_sort(int ac, void **av, int cmpf());
int				ft_strappendbytes(char **str, char *to_append, size_t len);
intmax_t		ft_intlen(intmax_t n);
void			ft_strreplace(char **to_replace, char *new);
void			ft_arraydel(void ***array, void delf(void **));
char			**ft_strfoversplit(const char *s, int should_split(int c));
bool			ft_getopt(struct s_ft_getopt *opt, int argc, char **argv,
					const char *optstring);

/*
** LINKED LIST
*/

/*
** list - double linked list implementation.
**
** This linked list implementation has been inspired by the list.h from the
** Linux kernel.
**
** The s_list2_conn struct contains pointers to the next and previous
** s_list2_conn structs. The functions contained in this header will malipulate
** these pointers. The struct contains only those pointers and therefor no
** content. It should not be used standalone. Instead, put it inside of a
** parrent struct as follows:
**
** struct s_example_node
** {
**   char         *foo;
**   int          bar;
**   [etc...]
**   t_list2_conn conn;
** }
**
** To insert an element, malloc the aforementioned struct and give list2_insert
** a pointer to the conn member of the struct.
**
** To get the s_example_node struct from a conn, an unpack function must be
** written. In this case the function would look like this:
**
** struct s_state_option    *unpack_example(struct s_list2_conn *conn)
** {
**     if (conn == NULL)
**         return (NULL);
**     return (struct s_example_node *)(
**         (char *)conn - offsetof(struct s_example_node, conn));
** }
**
** This function takes a pointer to the conn member of the example struct, and
** returns a pointer to the example struct itself. It does this by calculating
** the offset of the conn member relative to the start of the example struct.
*/

typedef struct	s_list_conn
{
	struct s_list_conn	*prev;
	struct s_list_conn	*next;
}				t_list_conn;

typedef struct	s_list_meta
{
	struct s_list_conn	*first;
	struct s_list_conn	*last;
	size_t				len;
}				t_list_meta;

void			ft_list_insert(
					t_list_meta *meta,
					t_list_conn *prev,
					t_list_conn *new);

void			ft_list_unlink(
					t_list_meta *meta,
					t_list_conn *conn);

#endif
