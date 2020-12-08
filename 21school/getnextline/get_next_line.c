/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:13:15 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/28 15:16:00 by rcaraway         ###   ########.fr       */
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

int main()
{
	int a = open("file.txt", O_RDONLY);
	char *s;
	get_next_line(a, &s);
	printf("%s\n", s);
	get_next_line(0, &s);
	printf("%s\n", s);

}
