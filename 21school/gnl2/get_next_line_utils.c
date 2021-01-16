/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:47:14 by rcaraway          #+#    #+#             */
/*   Updated: 2021/01/16 21:56:10 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_clrlst(char **s)
{
	int i;

	if (!s)
		return (1);
	i = 0;
	while ((*s)[i])
		(*s)[i++] = 0;
	return (1);
}

t_list	*getlist(int fd, t_list *lst)
{
	int i;

	i = BUFFER_SIZE;
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
		if (!(lst->next->buf = malloc(BUFFER_SIZE + 1)))
		{
			free(lst->next);
			return (0);
		}
		while (i >= 0)
			(lst->next->buf)[i--] = 0;
		return (lst->next);
	}
}

int		ft_realloc(char **s, int num)
{
	char	*tmp;
	int		i;
	char	*tmp2;

	if (!(tmp = malloc((1 + num) * BUFFER_SIZE + 1)))
		return (0);
	i = 0;
	while ((*s)[i])
	{
		tmp[i] = (*s)[i];
		i++;
	}
	while (i < (1 + num) * BUFFER_SIZE + 1)
		tmp[i++] = 0;
	tmp2 = *s;
	*s = tmp;
	ft_clrlst(&tmp2);
	free(tmp2);
	return (1);
}

int		ft_getline(int fd, char **line, t_list *lst, int i)
{
	int	j;
	int tmp;

	if ((j = 1) == 1 && !line)
		return (-1);
	*line = malloc(BUFFER_SIZE + 1);
	(*line)[BUFFER_SIZE] = 0;
	while (lst->buf[lst->pos] || (ft_clrlst(&(lst->buf)) && (tmp = read(fd, lst->buf, BUFFER_SIZE))
				&& clrbuf(&(lst->buf), tmp) && (lst->pos = 0) == 0))
	{
		while ((lst->buf)[lst->pos])
		{
			(*line)[i++] = lst->buf[lst->pos++];
			if ((*line)[i - 1] == '\n' || (*line)[i - 1] == 4 || (*line)[i - 1] == 0)
			{
				(*line)[i - 1] = '\0';
				clrbuf(line,i);
				if (lst->buf[lst->pos] == 0 && lst->buf[lst->pos - 1] != '\n' && ft_clrlst(&(lst->buf))
						&& (lst->pos = 0) == 0 && !(read(fd, lst->buf, BUFFER_SIZE)))
					return (0);
				return (1);
			}
		}
		lst->pos = 0;
		ft_clrlst(&(lst->buf));
		ft_realloc(line, j++);
	}
	return (0);
}
