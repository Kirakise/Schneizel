/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:33:19 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/30 16:31:54 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	makenode(t_arg **arg)
{
	(*arg)->fpos = 0;
	(*arg)->fzer = 0;
	(*arg)->fposzer = 0;
	(*arg)->minpos = -2;
	(*arg)->pos = -2;
	(*arg)->fnul = 0;
	(*arg)->fstr = 0;
	(*arg)->ffree = 0;
}

void	getform2(const char ***s, t_arg **arg)
{
	if (***s == '.' && (**s)++)
	{
		if (***s == '*')
			(*arg)->minpos = -1;
		else
		{
			(*arg)->fposzer = 1;
			(*arg)->minpos = ft_atoi(**s);
		}
	}
	while (***s != '%' && isarg(***s))
		(**s)++;
	if (***s == '%')
		(*arg)->arg = ft_strdup("%");
}

int		ft_printd2(t_arg *arg, int i, int j, int e)
{
	if (*(arg->arg) == '-' && arg->fzer && arg->minpos +
			ft_strlen(arg->arg) == -2 && (j = 1) && ++i)
		write(1, arg->arg, 1);
	while (arg->pos-- > 0 && ++i)
		if (arg->fzer == 0 || arg->minpos + ft_strlen(arg->arg) != -2)
			write(1, " ", 1);
		else
			write(1, "0", 1);
	if (*(arg->arg) == '-' && j != 1 && (j = 1) && ++i)
		write(1, arg->arg, 1);
	while (arg->minpos-- + j > 0 && ++i)
		write(1, "0", 1);
	if (e)
		i += ft_putstr_bonus(arg->arg + j);
	return (i);
}

int		ft_printd3(t_arg *arg, int i, int j, int e)
{
	if (arg->arg[0] == '-' && (j = 1) && ++i)
		write(1, arg->arg, 1);
	while (arg->minpos-- + j > 0 && ++i)
		write(1, "0", 1);
	if (e)
		i += ft_putstr_bonus(arg->arg + j);
	while (arg->pos-- > 0 && ++i)
		write(1, " ", 1);
	return (i);
}

int		ft_printd(t_arg *arg)
{
	int j;
	int e;
	int i;

	i = 0;
	j = 0;
	if (arg->minpos == 0 && arg->fposzer == 1 && ft_strncmp(arg->arg, "0", 3))
		arg->minpos = -2;
	e = arg->minpos;
	if (!e)
		arg->pos = arg->pos;
	else if (ft_strlen(arg->arg) > arg->minpos || arg->minpos == -2)
		arg->pos -= ft_strlen(arg->arg);
	else
		arg->pos -= arg->arg[0] == '-' ? arg->minpos + 1 : arg->minpos;
	arg->minpos -= ft_strlen(arg->arg);
	if (arg->fpos == 0)
		i = ft_printd2(arg, i, j, e);
	else
		i = ft_printd3(arg, i, j, e);
	free(arg->arg);
	free(arg);
	return (i);
}
