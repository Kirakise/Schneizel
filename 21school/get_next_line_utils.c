#include "get_next_line.h"


t_list *get_list(t_list *lst, int fd)
{
	t_list *tmp = lst;

	while (tmp->next)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->fd == fd)
		return (tmp);
	tmp->next = malloc(sizeof(struct list));
	tmp = tmp->next;
	tmp->fd = fd;
	tmp->i = 0;
	return (tmp);
}

int ft_realloc(char **s)
{
	char *new;
	int	i;

	if (*s == NULL)
	{
		*s = malloc(BUFFER_SIZE);
		return (1);
	}
	new = malloc(sizeof(*s) + BUFFER_SIZE);
	i = 0;
	while ((*s)[i])
	{
		new[i] = (*s)[i];
		i++;
	}
	*s = new;
	return (1);
}

char *ft_getline(t_list *lst, char **line, int fd)
{
	char *s;
	char *tmp;
	int j;

	j = 0;
	s = malloc(BUFFER_SIZE);
	tmp = s;
	if ((lst->buf)[lst->i] == '\n')
		while(++(lst->i) < BUFFER_SIZE)
		{
			if ((lst->buf)[lst->i] == '\n')
			{
				s[j] = '\0';
				return (s);
			}
			s[j++] = (lst->buf)[lst->i];
		}
	while (read(lst->fd, &(lst->buf), BUFFER_SIZE) == BUFFER_SIZE)
	{
		while(++(lst->i) < BUFFER_SIZE)
		{
			if ((lst->buf)[lst->i] == '\n')
			{
				s[j] = 0;
				return (s);
			}
			s[j++] = (lst->buf)[lst->i];
		}
		lst->i = 0;
		ft_realloc(&s);
	}
	return (0);
}
