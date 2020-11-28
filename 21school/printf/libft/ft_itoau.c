/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:47:53 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/25 18:53:17 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getlen(long long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoau(long long n)
{
	char		*s;
	size_t		len;
	long long	tmp;

	if (n == 0)
		return (ft_strdup("0"));
	len = getlen(n);
	tmp = n;
	if (n < 0)
		tmp = -tmp;
	s = malloc(len);
	if (!s)
		return (0);
	ft_bzero(s, len);
	len--;
	while (tmp != 0)
	{
		s[--len] = tmp % 10 + 48;
		tmp /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
