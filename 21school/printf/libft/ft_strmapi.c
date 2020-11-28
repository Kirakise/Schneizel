/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:25:33 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/02 14:07:57 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (!s || !f)
		return (0);
	i = 0;
	tmp = malloc(ft_strlen(s) + 1);
	if (!tmp)
		return (0);
	tmp2 = tmp;
	while (*s)
		*tmp++ = f(i++, *s++);
	*tmp = 0;
	return (tmp2);
}
