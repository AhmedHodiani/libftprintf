NAME		= libftprintf.a
INCLUDE		= include
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I

SRC_FILES	= ft_printf ft_putaddress_fd ft_putchar_fd ft_putnbr_fd ft_putstr_fd ft_strlen ft_puthex_fd
SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		= .cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
