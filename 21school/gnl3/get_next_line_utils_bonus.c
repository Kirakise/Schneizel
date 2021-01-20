/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:53:02 by rcaraway          #+#    #+#             */
/*   Updated: 2021/01/20 18:53:03 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_bzero(char **s)
{
	int i;

	i = 0;
	while (i <= BUFFER_SIZE)
		(*s)[i++] = 0;
}

int				ft_strlen(char *s)
{
	int i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void			ft_strjoin(char **s1, char **s2)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = malloc(ft_strlen(*s1) + ft_strlen(*s2) + 1);
	while ((*s1)[i])
	{
		tmp[i] = (*s1)[i];
		i++;
	}
	while ((*s2)[j])
		tmp[i++] = (*s2)[j++];
	tmp[i] = 0;
	free(*s1);
	*s1 = tmp;
}

static void		ft_costil(t_str **str, char **tmp)
{
	*tmp = malloc(BUFFER_SIZE + 1);
	ft_bzero(tmp);
	str++;
	str--;
}

int				ft_getline(int fd, t_str *str, char **line, int i)
{
	char *tmp;

	ft_costil(&str, &tmp);
	while ((str->buf[str->pos]) || (read(fd, str->buf, BUFFER_SIZE)
				&& !(str->pos = 0)))
	{
		while (str->buf[str->pos] != 0 && (tmp[i++] = str->buf[str->pos++]))
		{
			if (tmp[i - 1] == '\n' || tmp[i - 1] == 4)
			{
				tmp[i - 1] = 0;
				ft_strjoin(line, &tmp);
				free(tmp);
				if (!(str->buf[str->pos]))
					ft_bzero2(&(str->buf[0]));
				return (1);
			}
		}
		i = 0;
		ft_strjoin(line, &tmp);
		ft_bzero2(&(str->buf[0]));
		ft_bzero(&tmp);
	}
	free(tmp);
	return (0);
}
