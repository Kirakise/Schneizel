/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:05:54 by rcaraway          #+#    #+#             */
/*   Updated: 2021/01/19 17:11:50 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_str	arr[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, NULL, 0))
		return (-1);
	*line = malloc(1);
	**line = 0;
	return (ft_getline(fd, &(arr[fd]), line, 0));
}