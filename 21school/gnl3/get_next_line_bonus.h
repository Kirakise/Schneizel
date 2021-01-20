/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:52:42 by rcaraway          #+#    #+#             */
/*   Updated: 2021/01/20 18:52:43 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_str{
	int			fd;
	int			pos;
	char		buf[BUFFER_SIZE + 1];
}				t_str;
int				get_next_line(int fd, char **line);
void			ft_bzero(char **s);
int				ft_strlen(char *s);
void			ft_strjoin(char **s1, char **s2);
int				ft_getline(int fd, t_str *str, char **line, int i);
void			ft_bzero2(char *s);

#endif
