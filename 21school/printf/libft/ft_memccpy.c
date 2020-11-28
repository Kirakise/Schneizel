/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:16:21 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/02 13:25:54 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *to, void *from, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*s2;
	unsigned char	wtf;

	s = to;
	wtf = (unsigned char)c;
	s2 = from;
	while (n--)
	{
		*s = *s2;
		if (*s2 == wtf)
			return ((void *)++s);
		s++;
		s2++;
	}
	return (0);
}
