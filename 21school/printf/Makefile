SRCS = $(wildcard *.c) $(wildcard libft/*.c)
OBJS = $(SRCS:%.c=%.o)

all: $(OBJS) 
	clang -g -Ilibft $^

%.o: %.c
	cc -c -g -Ilibft $^ -o $@

clean:
	rm -rf libft/*.o *.o
	rm a.out
re: clean all
