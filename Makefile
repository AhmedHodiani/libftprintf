BUILD_PATH ?= ./build
LIB_NAME = $(BUILD_PATH)/libftprintf.a

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
OBJS		= $(SRCS:src/%.c=$(BUILD_PATH)/obj/%.o)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rcs $(LIB_NAME) $(OBJS)

$(BUILD_PATH)/obj/%.o: src/%.c
	@mkdir -p $(BUILD_PATH)/obj/helpers
	@mkdir -p $(BUILD_PATH)/obj/buggers
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_PATH)/obj

fclean: clean
	@rm -rf $(BUILD_PATH)

re: fclean all

.PHONY: all clean fclean re
