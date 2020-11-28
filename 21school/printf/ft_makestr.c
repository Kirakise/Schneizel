/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:22:59 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/28 18:23:36 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*getpointer(void *s)
{
	uintptr_t	tmp;
	char		*s1;

	tmp = (uintptr_t)s;
	s1 = ft_itoap(tmp, 0);
	return (s1);
}

int		makearg2(char c, va_list **lst, t_arg **arg)
{
	if (c == 'd' || c == 'i')
	{
		if (!((*arg)->arg = ft_itoa(va_arg(**lst, int))))
		{
			free(*arg);
			return (0);
		}
	}
	else if (c == 'u')
	{
		if (!((*arg)->arg = ft_itoau(va_arg(**lst, unsigned int))))
		{
			free(*arg);
			return (0);
		}
	}
	return (makearg3(c, lst, arg));
}

int		makearg(char c, va_list **lst, t_arg **arg)
{
	if (c == 'c')
	{
		if (!((*arg)->arg = malloc(2)))
		{
			free(*arg);
			return (0);
		}
		(*arg)->ffree = 1;
		(*arg)->arg[0] = va_arg(**lst, int);
		if ((*arg)->arg[0] == 0)
			(*arg)->fnul = 1;
		(*arg)->arg[1] = '\0';
		(*arg)->fstr = 1;
	}
	else if (c == 'p')
		if (!((*arg)->arg = getpointer(va_arg(**lst, void *))))
		{
			free(*arg);
			return (0);
		}
	return (makearg2(c, lst, arg));
}

int		printargstr(t_arg *arg)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (arg->arg == 0)
		arg->arg = "(null)";
	arg->minpos = arg->minpos == -2 ? ft_strlen(arg->arg) : arg->minpos;
	if (arg->fpos == 0)
		j += printargstr2(arg, i, j);
	else
	{
		while (((arg->arg[i] && i < arg->minpos) || arg->fnul) && ++j)
		{
			if (arg->arg[i] == 0 && arg->fnul)
				arg->fnul = 0;
			write(1, &(arg->arg[i++]), 1);
		}
		while (i++ < arg->pos && ++j)
			write(1, " ", 1);
	}
	if (arg->ffree)
		free(arg->arg);
	free(arg);
	return (j);
}
