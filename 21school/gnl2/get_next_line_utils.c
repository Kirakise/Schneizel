/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:47:14 by rcaraway          #+#    #+#             */
/*   Updated: 2020/12/09 17:26:58 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clrlst(t_list *lst)
{
	if (!lst)
		return ;
	if (lst->next)
		ft_clrlst(lst->next);
	if (lst->buf)
		free(lst->buf);
	free(lst);
}

t_list	*getlist(int fd, t_list *lst)
{
	if (lst->fd == fd)
		return (lst);
	else if (lst->next)
		return (getlist(fd, lst->next));
	else
	{
		if (!(lst->next = malloc(sizeof(struct s_list))))
			return (0);
		lst->next->next = 0;
		lst->next->fd = fd;
		lst->next->pos = 0;
		if (!(lst->next->buf = malloc(2 * BUFFER_SIZE)))
		{
			free(lst->next);
			return (0);
		}
		return (lst->next);
	}
}

int		ft_realloc(char **s, int num)
{
	char	*tmp;
	int		i;

	if (!*s)
	{
		i = 0;
		if (!(*s = malloc(2 * BUFFER_SIZE)))
			return (0);
		while (i < 2 * BUFFER_SIZE)
			(*s)[i++] = 0;
		return (1);
	}
	if (!(tmp = malloc((2 + num) * BUFFER_SIZE)))
		return (0);
	i = 0;
	while ((*s)[i])
	{
		tmp[i] = (*s)[i];
		i++;
	}
	while (i < (2 + num) * BUFFER_SIZE)
		tmp[i++] = 0;
	free(*s);
	*s = tmp;
	return (1);
}

int		ft_getline(int fd, char **line, t_list *lst, int i)
{
	int	j;

	if ((j = 1) == 1 && !line)
		return (-1);
	i = 0;
	*line = malloc(2 * BUFFER_SIZE);
	while (lst->buf[lst->pos] || (read(fd, lst->buf, BUFFER_SIZE)
				&& (lst->pos = 0) == 0))
	{
		while (lst->buf[lst->pos] != 0)
		{
			(*line)[i++] = lst->buf[lst->pos++];
			if ((*line)[i - 1] == '\n' || (*line)[i - 1] == 4)
			{
				(*line)[i - 1] = '\0';
				return (1);
			}
		}
		lst->pos = 0;
		lst->buf[0] = 0;
		ft_realloc(line, j++);
	}
	if (!**line)
		return (1);
	return (0);
}
