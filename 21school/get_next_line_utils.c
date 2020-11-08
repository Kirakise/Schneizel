#include "get_next_line.h"


t_list *get_list(t_list *lst, int fd)
{
	t_list *tmp = lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp->next = malloc(sizeof(struct list));
	tmp = tmp->next;
	tmp->fd = fd;
	return (tmp);
}

int ft_realloc(char **s)
{
	char *new;
	int	i;

	if (*s = NULL)
	{
		*s = malloc(BUFFER_SIZE);
		return (1);
	}
	new = malloc(sizeof(*s) + 32);
	i = 0;
	while ((*s)[i])
		new[i] = (*s)[i++];
	free(*s);
	*s = new;
}

char *ft_getline(t_list *lst, char **line, int fd)
{
	char *s;
	char *tmp;

	s = malloc(BUFFER_SIZE);
	tmp = s;
	if ((lst->buf)[lst->i] == '\n')
		while(++(lst->i) < BUFFER_SIZE && (lst->buf)[lst->i] != '\n')
			*s++ = (lst->buf)[lst->i];	
	if (*(s - 1) == '\n')
	{
		*(s - 1) = 0;
		return (s);
	}
	while (read(lst->fd, &(lst->buf), BUFFER_SIZE) == BUFFER_SIZE)
	{
		while(++(lst->i) < BUFFER_SIZE && (lst->buf)[lst->i] != '\n')
			*s++ = (lst->buf)[lst->i];
		if (*(s - 1) == '\n')
		{
			*(s - 1) = 0;
			return (s);
		}
		ft_realloc(&s);
	}
}
