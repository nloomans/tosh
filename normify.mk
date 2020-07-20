# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_select                                          :+:    :+:             #
#                                                      +:+                     #
#    By: Noah Loomans                                 +#+                      #
#        <nloomans@student.codam.nl>                 +#+                       #
#                                                   #+#    #+#                 #
#    License: GPLv3                                ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=21sh

all: $(NAME)

# Libaries #--------------------------------------------------------------------

LIBFT_NAME=		ft
LIBFT_DIR=		libft
LIBFT_A=		$(LIBFT_DIR)/lib$(LIBFT_NAME).a
LIBFT_IFLAGS=	-I $(LIBFT_DIR)
LIBFT_LFLAGS=	-L $(LIBFT_DIR) -l$(LIBFT_NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

FTPRINTF_NAME=		ftprintf
FTPRINTF_DIR=		libftprintf
FTPRINTF_A=			$(FTPRINTF_DIR)/lib$(FTPRINTF_NAME).a
FTPRINTF_IFLAGS=	-I $(FTPRINTF_DIR)
FTPRINTF_LFLAGS=	-L $(FTPRINTF_DIR) -l$(FTPRINTF_NAME) -lcurses

$(FTPRINTF_A):
	$(MAKE) -C $(FTPRINTF_DIR)

# Definitions #-----------------------------------------------------------------

SRC_DIR=		src
OBJ_DIR=		obj

SRC_FILES=		%SRC_FILES%
INC_FILES=		%INC_FILES%
OBJ_FILES=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))


CFLAGS=			-Werror -Wall -Wextra -O2 -g
IFLAGS=			$(LIBFT_IFLAGS) $(FTPRINTF_IFLAGS)
LFLAGS=			$(LIBFT_LFLAGS) $(FTPRINTF_LFLAGS)

# Regular rules #---------------------------------------------------------------

$(NAME): $(OBJ_FILES) $(LIBFT_A) $(FTPRINTF_A)
	$(CC) -o $@ $(OBJ_FILES) $(CFLAGS) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@mkdir -p $$(dirname $@)
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

# Phonies #---------------------------------------------------------------------

clean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FTPRINTF_DIR) fclean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FTPRINTF_DIR) fclean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

# Special #---------------------------------------------------------------------

.SECONDARY: $(OBJ_FILES)
.PHONY: all clean fclean re
