SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:%.c=%.o)
NAME = result
CC = clang

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -framework OpenGL -framework AppKit $^ libmlx.a -o $(NAME)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $^ -o $@
clean:
	rm $(OBJS)
fclean: clean
	rm result
re: fclean all
