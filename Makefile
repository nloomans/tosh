# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nloomans <nloomans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/19 10:52:40 by nloomans       #+#    #+#                 #
#    Updated: 2019/03/21 13:35:24 by nloomans      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=			libft.a
CC=				gcc
CFLAGS=			-Wall -Wextra -Werror -g
SRC_FILES=		\
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
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
