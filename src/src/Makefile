NAME	= fractol

SRC		= $(wildcard *.c)

OBJS	= $(SRC:.c=.o)

GCC		= cc
MLX		= -lmlx -framework OpenGL -framework AppKit
FLAGS	= -Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(GCC) $(MLX) $(FLAGS) -c $(SRCS) -I ./
all: $(NAME)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
