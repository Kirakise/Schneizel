SRCS = $(wildcard src/*.c) $(wildcard src/math/*.c) $(wildcard src/parcer/*.c) $(wildcard src/utils/*.c) $(wildcard src/constructors/*.c) $(wildcard src/mlx/*.c)
OBJS = $(SRCS:%.c=%.o)
NAME = result
CC = clang

all: $(NAME)

linux: $(OBJS)
	$(CC) -g -lmlx  -lX11 -lXext $^ libmlx.a -o $(NAME) -lm
$(NAME): $(OBJS)
	$(CC) -g libmlx_mac.a -framework OpenGL -framework AppKit $^ -o $(NAME)
%.o: %.c
	$(CC) -g -Wall -Wextra -Werror -c $^ -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f result
re: fclean all
