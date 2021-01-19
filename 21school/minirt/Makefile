SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=%.o)
NAME = result

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -framework OpenGL -framework AppKit $^ libmlx.a -o $(NAME)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $^ -o $@

