# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nloomans <nloomans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/19 10:52:40 by nloomans       #+#    #+#                 #
#    Updated: 2019/03/20 18:41:50 by nloomans      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=			libft.a
CC=				gcc
CFLAGS=			-Wall -Wextra -Werror
SRC_FILES=		\
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_atoi.c \
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
	rm -f $(OBJ_FILES) $(DEBUG_FILES)
	rm -fd $(OBJ_FOLDER) $(DEBUG_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all
