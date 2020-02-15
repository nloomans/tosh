# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nloomans <nloomans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/06 15:11:37 by nloomans       #+#    #+#                 #
#    Updated: 2019/06/12 14:14:48 by nloomans      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=tester

all: $(NAME)

##########
# Colors #
##########

OK_COLOR=\x1b[32;01m
RESET=\x1b[0m
UNDERLINE=\x1b[4m
BLUE=\x1b[36m
RED=\x1b[31m

##################
# Auto-configure #
##################

UNAME=$(shell uname)

############
# Libaries #
############

# Printf

LIBFTPRINTF_NAME=	ftprintf
LIBFTPRINTF_DIR=	..
LIBFTPRINTF_A=		$(LIBFTPRINTF_DIR)/lib$(LIBFTPRINTF_NAME).a
LIBFTPRINTF_IFLAGS=	-I $(LIBFTPRINTF_DIR) -I $(LIBFTPRINTF_DIR)/inc
LIBFTPRINTF_LFLAGS=	-L $(LIBFTPRINTF_DIR) -l$(LIBFTPRINTF_NAME)
LIBFTPRINTF_DEPS=	$(wildcard $(LIBFTPRINTF_DIR)/src/*.c) \
					$(wildcard $(LIBFTPRINTF_DIR)/inc/*.h)

$(LIBFTPRINTF_A): $(LIBFTPRINTF_DEPS)
	@$(MAKE) -C $(LIBFTPRINTF_DIR)

libftprintf_clean:
	@$(MAKE) -C $(LIBFTPRINTF_DIR) clean

libftprintf_fclean:
	@$(MAKE) -C $(LIBFTPRINTF_DIR) fclean

# Criterion
LIBCRITERION_NAME=		criterion
ifeq ($(UNAME),Darwin)
LIBCRITERION_A=			$(HOME)/.brew/lib/lib$(LIBCRITERION_NAME).dylib
LIBCRITERION_IFLAGS=	-I $(HOME)/.brew/include
LIBCRITERION_LFLAGS=	-L $(HOME)/.brew/lib -l$(LIBCRITERION_NAME)

$(LIBCRITERION_A):
	@if ! [ -f $(LIBCRITERION_A) ]											;\
	then	echo "Please install criterion using first using:" >&2			;\
			echo >&2														;\
			echo "    brew install criterion" >&2							;\
			exit 1															;\
	fi
else
LIBCRITERION_LFLAGS=	-l$(LIBCRITERION_NAME)
endif

###########
# Project #
###########

CC=				gcc
SRC_DIR=		./spec
INC_DIR=		./inc
OBJ_DIR=		./.obj
EXTRA=			# Custom CFLAGS added by the user
CFLAGS=			-Werror -Wall -Wextra -O2 $(EXTRA)
IFLAGS=			$(LIBFTPRINTF_IFLAGS) $(LIBCRITERION_IFLAGS) -I $(INC_DIR)
LFLAGS=			$(LIBFTPRINTF_LFLAGS) $(LIBCRITERION_LFLAGS)

SRC_FILES=		$(wildcard $(SRC_DIR)/*.c)
INC_FILES=		$(wildcard $(INC_DIR)/*.h)
OBJ_FILES=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(NAME): $(LIBFTPRINTF_A) $(LIBCRITERION_A) $(OBJ_FILES)
	@printf " λ Creating binary $(OK_COLOR)$(UNDERLINE)$@$(RESET)\n"
	@$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@mkdir -p $(OBJ_DIR)
	@printf " λ Making object $(UNDERLINE)$(BLUE)$<$(RESET)\n"
	@$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

debug:
	$(MAKE) -B "EXTRA=$(EXTRA) -g"

test: $(NAME)
	@./$(NAME)

clean: libftprintf_clean
	@printf "$(RED)Cleaning objects$(RESET)\n"
	@rm -rf $(OBJ_DIR)

fclean: clean libftprintf_fclean
	@printf "$(RED)Cleaning $(NAME)$(RESET)\n"
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.SECONDARY: $(OBJ_FILES)
.PHONY: \
	all \
	debug \
	clean \
	libft_clean \
	re \
