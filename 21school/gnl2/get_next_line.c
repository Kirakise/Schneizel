/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:39:48 by rcaraway          #+#    #+#             */
/*   Updated: 2020/12/09 17:02:57 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list			*tmp;
	int				i;

	if (fd < 0 || !line)
		return (-1);
	if (!lst)
	{
		lst = malloc(sizeof(struct s_list));
		lst->fd = -1;
		lst->next = 0;
	}
	if (!(tmp = getlist(fd, lst)))
	{
		ft_clrlst(lst);
		return (-1);
	}
	i = ft_getline(fd, line, tmp, 0);
	return (i);
}
