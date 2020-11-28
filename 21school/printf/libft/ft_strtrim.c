/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:59:44 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/02 18:11:19 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_str(char const *s1, char c)
{
	if (!s1)
		return (0);
	while (*s1)
		if (*s1++ == c)
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*ret;
	char	*tmp;
	int		i;

	if (!s1 || !set)
		return (0);
	i = 0;
	size = ft_strlen(s1);
	while (is_in_str(set, s1[i]) && s1[i])
		i++;
	while (is_in_str(set, s1[size - 1]) && size - 1 >= i)
		size--;
	if (size - i + 1 < 1)
		return ("");
	ret = malloc(size - i + 1);
	if (!ret)
		return (0);
	tmp = ret;
	while (i < size)
		*tmp++ = s1[i++];
	*tmp = 0;
	return (ret);
}
