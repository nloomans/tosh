# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nloomans <nloomans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/19 10:52:40 by nloomans       #+#    #+#                 #
#    Updated: 2019/04/09 17:42:50 by nloomans      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=			libft.a

##########
# Colors #
##########

GREEN=\x1b[32;01m
RED=\x1b[31m
RESET=\x1b[0m

###########
# Project #
###########

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
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				\
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				\
				ft_isspace.c \
				ft_strdropwhile.c \
				ft_strstrim.c \
				ft_lstpush.c \
				ft_lstpop.c \
				ft_print_memory.c \
				ft_sort.c \
				ft_strappendbytes.c \

OBJ_DIR=		obj
OBJ_FILES=		$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

CFLAGS=			-Wall -Wextra -Werror

all: $(NAME)

test: $(NAME) $(DEBUG_FILES)

$(NAME): $(OBJ_FILES)
	@printf "$(GREEN)ARCHIVE$(RESET)\t%s\n" $@

	@ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	@printf "$(GREEN)CC$(RESET)\t%s\n" $@

	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
