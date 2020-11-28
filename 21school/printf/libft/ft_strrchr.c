/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:56:46 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 20:57:22 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *tmp;

	tmp = 0;
	while (*s)
	{
		if (*s != c)
			s++;
		else
			tmp = s++;
	}
	if (*s == c)
		return ((char *)s);
	return ((char *)tmp);
}
