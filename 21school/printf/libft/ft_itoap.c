/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:46:59 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/28 17:59:14 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		intsize(size_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	else
		while (n != 0)
		{
			i++;
			n /= 16;
		}
	return (i);
}

int				dothefile(size_t n, int big, char **s, int i)
{
	size_t tmp;

	tmp = n;
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp >= 10)
		{
			if (big)
				(*s)[--i] = tmp + 'A' - 10;
			else
				(*s)[--i] = tmp + 'a' - 10;
		}
		else
			(*s)[--i] = tmp + '0';
		n /= 16;
	}
	return (i);
}

char			*ft_itoap(size_t n, int big)
{
	char	*s;
	int		i;

	i = intsize(n) + 3;
	s = malloc(i);
	if (!s)
		return (0);
	s[0] = '0';
	s[1] = 'x';
	if (n == 0)
	{
		s[2] = '0';
		s[3] = 0;
		return (s);
	}
	s[--i] = 0;
	i = dothefile(n, big, &s, i);
	return (s);
}
