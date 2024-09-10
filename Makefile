NAME		= libftprintf.a
CC			= cc
INCLUDE		= include
CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE)

SRC		= $(wildcard src/*.c src/helpers/*.c)
OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

obj/%.o: src/%.c
	@mkdir -p obj
	@mkdir -p obj/helpers
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
