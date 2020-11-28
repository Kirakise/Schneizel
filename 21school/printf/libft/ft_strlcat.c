/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:06:50 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 19:09:32 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	int i;
	int sizet;

	if (ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	i = ft_strlen(dst) + ft_strlen(src);
	sizet = size - ft_strlen(dst) - 1;
	if (sizet < 0)
		return (i);
	while (*dst)
		dst++;
	while (sizet-- && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (i);
}
