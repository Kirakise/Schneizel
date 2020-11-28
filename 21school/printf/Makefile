SRCS = $(wildcard *.c) $(wildcard libft/*.c)
OBJS = $(SRCS:%.c=%.o)
NAME = libftprintf.a

$(NAME): all

all: $(OBJS) 
	ar -rc $(NAME) $^

aout: $(OBJS)
	clang -g $^

%.o: %.c
	cc -c -g -Ilibft $^ -o $@

clean:
	rm -rf libft/*.o *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
