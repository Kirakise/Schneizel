/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:08:06 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/09 14:12:18 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 32

typedef	struct		s_list
{
	int				fd;
	int				i;
	char			buf[BUFFER_SIZE + 1];
	struct list		*next;
}					t_list;

int					ft_getline(t_list *lst, char ***line, int fd);
t_list				*get_list(t_list *lst, int fd);

#endif
