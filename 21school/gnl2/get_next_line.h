/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:49:49 by rcaraway          #+#    #+#             */
/*   Updated: 2020/12/12 20:21:40 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_list{
	int				fd;
	struct s_list	*next;
	char			*buf;
	int				pos;
}					t_list;

int					get_next_line(int fd, char **line);
int					ft_getline(int fd, char **line, t_list *lst, int i);
int					ft_realloc(char **s, int num);
void				ft_clrlst(char **s);
t_list				*getlist(int fd, t_list *lst);

#endif
