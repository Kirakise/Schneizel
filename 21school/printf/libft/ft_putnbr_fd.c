/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:17:21 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/06 19:19:01 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		intsize(int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*revstr(char *s)
{
	int start;
	int end;
	int tmp;

	start = 0;
	end = ft_strlen(s) - 1;
	while (start < end)
	{
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		start++;
		end--;
	}
	return (s);
}

void			ft_putnbr_fd(int n, int fd)
{
	int		plus;
	char	s1[intsize(n) + 1];
	char	*s;
	char	*tmp;

	plus = 0;
	s = s1;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	tmp = s;
	if (n < 0)
		plus = 1;
	while (n != 0)
	{
		*s++ = plus == 1 ? -(n % 10) + '0' : n % 10 + '0';
		n /= 10;
	}
	if (plus)
		*s++ = '-';
	*s = 0;
	ft_putstr_fd(revstr(tmp), fd);
}
