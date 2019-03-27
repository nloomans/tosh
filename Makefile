# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nloomans <nloomans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/19 10:52:40 by nloomans       #+#    #+#                 #
#    Updated: 2019/03/27 13:39:21 by nloomans      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=			libft.a
CC=				gcc
CFLAGS=			-Wall -Wextra -Werror -g
SRC_FILES=		\
				ft_memset.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				\
				ft_bzero.c \
				\
				ft_atoi.c \
				\
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				\
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				\
				ft_isspace.c \
				ft_strdropwhile.c
OBJ_FOLDER=		.obj
OBJ_FILES=		$(patsubst %.c,$(OBJ_FOLDER)/%.o,$(SRC_FILES))
DEBUG_FOLDER=	debug
DEBUG_FILES=	$(patsubst %.c,$(DEBUG_FOLDER)/%,$(SRC_FILES))

all: $(NAME)

test: $(NAME) $(DEBUG_FILES)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

$(DEBUG_FOLDER)/%: %.test.c $(NAME) test_macros.h
	@mkdir -p $(DEBUG_FOLDER)
	$(CC) $(CFLAGS) -L. -lft -I. -o $@ $<

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(OBJ_FOLDER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_FOLDER) $(DEBUG_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ_FILES)
.PHONY: all test clean fclean re
