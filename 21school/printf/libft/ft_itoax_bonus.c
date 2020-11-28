/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoax_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:43:06 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/28 18:35:30 by rcaraway         ###   ########.fr       */
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

char			*ft_itoax_bonus(size_t n, int big)
{
	char	*s;
	int		i;
	int		tmp;

	i = intsize(n) + 1;
	if (n == 0)
		return (ft_strdup("0"));
	s = malloc(i);
	if (!s)
		return (0);
	s[--i] = 0;
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp >= 10)
			s[--i] = tmp + (big == 0 ? 'a' : 'A') - 10;
		else
			s[--i] = tmp + '0';
		n /= 16;
	}
	return (s);
}
