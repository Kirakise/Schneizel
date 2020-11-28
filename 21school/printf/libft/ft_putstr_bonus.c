/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:42:15 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/28 17:42:58 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_bonus(char *s)
{
	int i;

	i = 0;
	while (*s && ++i)
		write(1, s++, 1);
	return (i);
}