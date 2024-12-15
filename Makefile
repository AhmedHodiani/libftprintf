NAME		= libftprintf.a
CC			= cc
INCLUDE		= include
CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE)

SRC		=	src/ft_printf.c \
			src/ft_putaddress_fd.c \
			src/ft_puthex_fd.c \
			src/ft_putnbr_fd.c \
			src/ft_putstr_fd.c \
			src/ft_putunsigned_fd.c
HELPERS	=	helpers/hp_hexlen.c \
			helpers/hp_putchar_fd.c \
			helpers/hp_puthex_fd.c \
			helpers/hp_strlen.c
BUGGERS	=	buggers/bugger.c
OBJ		=	$(SRC:src/%.c=obj/src/%.o) \
			$(HELPERS:helpers/%.c=obj/helpers/%.o) \
			$(BUGGERS:buggers/%.c=obj/buggers/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

obj/%.o: %.c
	@mkdir -p obj/src
	@mkdir -p obj/helpers
	@mkdir -p obj/buggers
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
