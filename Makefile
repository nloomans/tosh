# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nloomans <nloomans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/06 15:11:37 by nloomans       #+#    #+#                 #
#    Updated: 2019/05/20 15:54:34 by nmartins      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

all: $(NAME)

##########
# Colors #
##########

OK_COLOR=\x1b[32;01m
RESET=\x1b[0m
UNDERLINE=\x1b[4m
BLUE=\x1b[36m
RED=\x1b[31m

############
# Libaries #
############

# Libft

LIBFT_NAME=		ft
LIBFT_DIR=		./libft
LIBFT_A=		$(LIBFT_DIR)/lib$(LIBFT_NAME).a
LIBFT_IFLAGS=	-I $(LIBFT_DIR)
LIBFT_LFLAGS=	-L $(LIBFT_DIR) -l$(LIBFT_NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

libft_clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean

###########
# Project #
###########

CC=				gcc
SRC_DIR=		./src
INC_DIR=		./inc
OBJ_DIR=		./.obj
EXTRA=			# Custom CFLAGS added by the user
CFLAGS=			-Werror -Wall -Wextra -O2 $(EXTRA)
IFLAGS=			$(LIBFT_IFLAGS) -I $(INC_DIR)
LFLAGS=			$(LIBFT_LFLAGS)

SRC_FILES=		$(wildcard $(SRC_DIR)/*.c)
INC_FILES=		$(wildcard $(INC_DIR)/*.h)
OBJ_FILES=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(NAME): $(LIBFT_A) $(OBJ_FILES)
	@cp -f $(LIBFT_A) $(NAME)
	@echo " λ Creating archive $(OK_COLOR)$(UNDERLINE)$(NAME)$(RESET)"
	@ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@mkdir -p $(OBJ_DIR)
	@printf " λ Making object $(UNDERLINE)$(BLUE)$<$(RESET)\n"
	@$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

debug:
	$(MAKE) -B "EXTRA=$(EXTRA) -g"

clean: libft_clean
	@echo "$(RED)Cleaning objects$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean libft_fclean
	@echo "$(RED)Cleaning $(NAME)$(RESET)"
	@rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.SECONDARY: $(OBJ_FILES)
.PHONY: \
	all \
	debug \
	clean \
	libft_clean \
	re \
