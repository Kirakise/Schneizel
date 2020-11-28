/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:50:20 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/02 13:36:20 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		checkstr(const char *haystack, const char *needle, size_t len)
{
	const char *tmp;
	const char *tmp2;

	tmp = haystack;
	tmp2 = needle;
	while (*needle && *haystack && len-- > 0)
	{
		if (*needle != *haystack)
		{
			needle = tmp2;
			haystack = tmp;
			break ;
		}
		needle++;
		haystack++;
	}
	haystack = tmp;
	if (*needle == '\0')
		return (1);
	else
		return (0);
}

char			*ft_strnstr(const char *haystack,
							const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle)
			if (checkstr(haystack, needle, len))
				return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
