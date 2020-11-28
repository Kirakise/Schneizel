/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:54:42 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 20:55:50 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, void *from, size_t len)
{
	static unsigned char	buf[1024 * 1024 * 1024];
	unsigned long			i;
	unsigned char			*s;
	unsigned char			*s2;

	s = to;
	s2 = from;
	if (s == 0 && s2 == 0)
		return (0);
	i = 0;
	while (i < len)
		buf[i++] = *s2++;
	i = 0;
	while (i < len)
		*s++ = buf[i++];
	return (to);
}
