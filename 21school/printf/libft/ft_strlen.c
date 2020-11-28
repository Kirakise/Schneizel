/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:20:46 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/04 14:42:01 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	size_t					i;
	const unsigned char		*s1;

	s1 = (const unsigned char *)s;
	i = 0;
	while (*s1++)
		i++;
	return (i);
}
