/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:14:34 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 19:15:23 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, char *src, size_t size)
{
	int	i;
	int	sizetmp;

	if (!dst || !src)
		return (0);
	sizetmp = size - 1;
	i = ft_strlen(src);
	if (sizetmp <= -1)
		return (i);
	while (*src && sizetmp)
	{
		*dst++ = *src++;
		sizetmp--;
	}
	*dst = '\0';
	return (i);
}
