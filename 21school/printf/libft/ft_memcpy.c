/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:46:01 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 20:50:04 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, void *from, size_t count)
{
	char	*s2;
	char	*s;

	if (to == 0 && from == 0)
		return (0);
	s = to;
	s2 = from;
	while (count--)
		*s++ = *s2++;
	return (to);
}
