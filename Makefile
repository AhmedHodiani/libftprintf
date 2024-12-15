NAME		= libftprintf.a
CC			= cc
INCLUDE		= include
CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE)

SRCS		= src/ft_printf.c \
				src/ft_putaddress_fd.c \
				src/ft_puthex_fd.c \
				src/ft_putnbr_fd.c \
				src/ft_putstr_fd.c \
				src/ft_putunsigned_fd.c \
				src/helpers/hp_hexlen.c \
				src/helpers/hp_putchar_fd.c \
				src/helpers/hp_puthex_fd.c \
				src/helpers/hp_strlen.c \
				src/buggers/bugger.c
OBJS		= $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

obj/%.o: src/%.c
	@mkdir -p obj/helpers
	@mkdir -p obj/buggers
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
