SRCS		= ft_printf.c
OBJS		= $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I$(LIBFT_PATH) -I.
NAME	= libftprintf.a


all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re:  fclean $(NAME)
