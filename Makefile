# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nloomans <nloomans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/19 10:52:40 by nloomans       #+#    #+#                 #
#    Updated: 2019/08/22 13:45:11 by nloomans      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=			libft.a

##########
# Colors #
##########

GREEN=\033[32;01m
RED=\033[31m
RESET=\033[0m

###########
# Project #
###########

SRC_DIR=		src
INC_DIR=		inc
OBJ_DIR=		obj

SRC_FILES=		\
				memset \
				memcpy \
				memccpy \
				memmove \
				memchr \
				memcmp \
				strlen \
				strdup \
				strcpy \
				strncpy \
				strcat \
				strncat \
				strlcat \
				strchr \
				strrchr \
				strstr \
				strnstr \
				strcmp \
				strncmp \
				\
				bzero \
				\
				atoi \
				\
				isalpha \
				isdigit \
				isalnum \
				isascii \
				isprint \
				toupper \
				tolower \
				\
				memalloc \
				memdel \
				strnew \
				strdel \
				strclr \
				striter \
				striteri \
				strmap \
				strmapi \
				strequ \
				strnequ \
				strsub \
				strjoin \
				strtrim \
				strsplit \
				itoa \
				putchar \
				putstr \
				putendl \
				putnbr \
				putchar_fd \
				putstr_fd \
				putendl_fd \
				putnbr_fd \
				\
				lstnew \
				lstdelone \
				lstdel \
				lstadd \
				lstiter \
				lstmap \
				\
				isspace \
				strdropwhile \
				strstrim \
				lstpush \
				lstpop \
				print_memory \
				sort \
				strappendbytes \
				intlen \
				getline \

INC_FILES=		libft.h inc/ft_getline.h
OBJ_FILES=		$(patsubst %,$(OBJ_DIR)/ft_%.o,$(SRC_FILES))

CFLAGS=			-Wall -Wextra -Werror
IFLAGS=			-I . -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@printf "$(GREEN)ARCHIVE$(RESET)\t%s\n" $@

	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@printf "$(GREEN)CC$(RESET)\t%s\n" $@

	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
