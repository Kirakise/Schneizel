/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:36:43 by rcaraway          #+#    #+#             */
/*   Updated: 2021/01/15 20:30:29 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		makearg3(char c, va_list **lst, t_arg **arg)
{
	if (c == 'x')
	{
		if (!((*arg)->arg = ft_itoax_bonus(va_arg(**lst, unsigned int), 0)))
		{
			free(*arg);
			return (0);
		}
	}
	else if (c == 'X')
	{
		if (!((*arg)->arg = ft_itoax_bonus(va_arg(**lst, unsigned int), 1)))
		{
			free(*arg);
			return (0);
		}
	}
	else if (c == 's')
	{
		(*arg)->arg = va_arg(**lst, char *);
		(*arg)->fstr = 1;
	}
	return (1);
}

int		printargstr2(t_arg *arg, int i, int j)
{
	arg->pos -= ft_strlen(arg->arg) > arg->minpos ?
		arg->minpos : ft_strlen(arg->arg);
	if (arg->fnul != 0)
		arg->pos--;
	while (arg->pos-- > 0 && ++j)
		write(1, " ", 1);
	while (((arg->arg[i] && i < arg->minpos) || arg->fnul) && ++j)
	{
		if (arg->arg[i] == 0 && arg->fnul)
			arg->fnul = 0;
		write(1, &(arg->arg[i++]), 1);
	}
	return (j);
}
