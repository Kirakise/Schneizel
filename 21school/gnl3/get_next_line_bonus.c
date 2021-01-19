/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:23:10 by rcaraway          #+#    #+#             */
/*   Updated: 2021/01/19 17:23:12 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_next_line(int fd, char **line)
{
	static t_str	arr[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, NULL, 0))
		return (-1);
	*line = malloc(1);
	**line = 0;
	return (ft_getline(fd, &(arr[fd]), line, 0));
}
