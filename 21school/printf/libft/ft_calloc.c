/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:10:45 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 19:11:38 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*tmp;
	int		temp;

	temp = size * count;
	p = malloc(count * size);
	if (p == 0)
		return (0);
	tmp = p;
	while (temp--)
		*tmp++ = 0;
	return (p);
}
