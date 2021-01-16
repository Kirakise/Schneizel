/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:39:48 by rcaraway          #+#    #+#             */
/*   Updated: 2021/01/16 22:11:58 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void m_cost(char **line)
{
	int i;
	char *tmp1;
	char *tmp2;

	i = 0;
	while ((*line)[i])
		i++;
	tmp1 = malloc(i + 1);
	tmp2 = *line;
	tmp1[i] = 0;
	while (--i >= 0)
		tmp1[i] = tmp2[i];
	free(tmp2);
	*line = tmp1;
}

int	clrbuf(char **s, int i)
{
	char c;
	int	tmp;

	if (!s)
		return (1);
	c = (*s)[i - 1];
	tmp = --i;
	while (i - tmp <= 1)
		(*s)[i++] = '\0';
	(*s)[tmp] = c;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list			*tmp;
	int				i;

	if (BUFFER_SIZE < 1 || !line || read(fd, NULL, 0))
		return (-1);
	if (!lst)
	{
		if (!(lst = malloc(sizeof(struct s_list))))
			return (-1);
		lst->fd = -2;
		lst->next = 0;
	}
	if (!(tmp = getlist(fd, lst)))
		return (-1);
	i = ft_getline(fd, line, tmp, 0);
	m_cost(line);
	return (i);
}
