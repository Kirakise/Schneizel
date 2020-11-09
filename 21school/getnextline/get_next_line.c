/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:13:15 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/09 14:57:43 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_list	lst;
	int				a;
	t_list			*l;

	l = get_list(&lst, fd);
	a = ft_getline(l, &line, fd);
	return (a);
}