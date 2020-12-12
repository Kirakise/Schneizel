/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:39:48 by rcaraway          #+#    #+#             */
/*   Updated: 2020/12/12 20:27:40 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		lst->fd = -1;
		lst->next = 0;
	}
	if (!(tmp = getlist(fd, lst)))
		return (-1);
	i = ft_getline(fd, line, tmp, 0);
	return (i);
}
