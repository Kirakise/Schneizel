#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 32

typedef	struct		list
{
	int		fd;
	int		i;
	char		buf[BUFFER_SIZE];
	struct list	*next;
}			t_list;

int	ft_getline(t_list *lst, char ***line, int fd);
t_list	*get_list(t_list *lst, int fd);

#endif
