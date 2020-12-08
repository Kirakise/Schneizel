#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_list{
	int	fd;
	struct s_list	*next;
	char	*buf;
	int	pos;
}		t_list;

int get_next_line(int fd, char **line);
int ft_getline(int fd, char **line, t_list *lst);
int ft_realloc(char **s, int num);
void ft_clrlst(t_list *lst);
t_list *getlist(int fd, t_list *lst);

#endif
