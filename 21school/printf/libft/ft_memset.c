/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:57:14 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/02 13:26:18 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int ch, size_t count)
{
	unsigned char *p;

	p = ptr;
	while (count--)
		*p++ = ch;
	return (ptr);
}
