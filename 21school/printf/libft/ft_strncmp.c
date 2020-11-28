/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:48:57 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 20:49:36 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *s3;
	const unsigned char *s4;

	s3 = (const unsigned char *)s1;
	s4 = (const unsigned char *)s2;
	while (n-- && (*s3 || *s4))
	{
		if (*s3 != *s4)
			return (*s3 - *s4);
		s3++;
		s4++;
	}
	return (0);
}
