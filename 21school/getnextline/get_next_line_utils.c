/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:16:35 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/28 15:19:01 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_list(t_list *lst, int fd)
{
	t_list *tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = (t_list *)tmp->next;
	}
	if (tmp->fd == fd)
		return (tmp);
	tmp->next = malloc(sizeof(struct s_list));
	tmp = (t_list *)tmp->next;
	tmp->fd = fd;
	tmp->i = 0;
	return (tmp);
}

int		checkret(int n, char *s)
{
	int i;

	i = 0;
	while (*s++)
		i++;
	if (n < 0)
		return (-1);
	if (i == 0)
		return (0);
	else
		return (1);
}

int		ft_realloc(char **s)
{
	char	*new;
	int		i;
	char	*tmp;

	tmp = *s;
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
	(*s)[i] = 0;
	*s = new;
	free(tmp);
	return (1);
}

int		proc_list(t_list *lst, char **s, int fd, char ***line)
{
	int j;
	int readint;

	readint = 0;
	j = 0;
	while ((readint = read(lst->fd, &(lst->buf), BUFFER_SIZE)) > 0)
	{
		while (lst->i < BUFFER_SIZE)
		{
			if ((lst->buf)[lst->i] == '\n' || (lst->buf)[lst->i] == 4)
			{
				(*s)[j] = '\n';
				(*s)[j] = 0;
				**line = *s;
				return (checkret(readint, *s));
			}
			(*s)[j++] = (lst->buf)[(lst->i)++];
		}
		lst->i = 0;
		ft_realloc(s);
	}
	**line = *s;
	return (checkret(readint, *s));
}

int		ft_getline(t_list *lst, char ***line, int fd)
{
	char	*s;
	int		j;
	int		readint;

	j = 0;
	readint = 0;
	s = malloc(2 * BUFFER_SIZE);
	if ((lst->buf)[lst->i] == '\n')
		while (++(lst->i) < BUFFER_SIZE)
		{
			if ((lst->buf)[lst->i] == '\n' || (lst->buf)[lst->i] == 4
					|| (lst->buf)[lst->i] == 0)
			{
				s[j] = '\n';
				s[j+1] = 0;
				**line = s;
				return (checkret(readint, s));
			}
			s[j++] = (lst->buf)[lst->i];
		}
	lst->i = 0;
	return (proc_list(lst, &s, fd, line));
}
