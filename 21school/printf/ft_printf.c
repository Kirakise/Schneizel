/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:52:43 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/28 18:25:34 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		isarg(char c)
{
	const char *s;

	s = "cspdiuxX";
	while (*s != c && *s)
		s++;
	if (!*s)
		return (1);
	return (0);
}

void	getform(const char ***s, t_arg **arg)
{
	makenode(arg);
	while (***s == '-' || ***s == '0')
	{
		if (***s == '-')
			(*arg)->fpos = 1;
		else
			(*arg)->fzer = 1;
		(**s)++;
	}
	if (***s > '0' && ***s <= '9')
		(*arg)->pos = ft_atoi(**s);
	else if (***s == '*')
		(*arg)->pos = -1;
	while (***s != '.' && isarg(***s) && ***s != '%')
		(**s)++;
	getform2(s, arg);
}

t_arg	*getarg(const char **s, va_list *lst)
{
	t_arg *arg;

	if (!(arg = malloc(sizeof(struct s_arg))))
		return (NULL);
	getform(&s, &arg);
	if (arg->pos == -1)
	{
		arg->pos = va_arg(*lst, int);
		if (arg->pos < 0)
		{
			arg->fpos = 1;
			arg->pos = -arg->pos;
		}
	}
	if (arg->minpos == -1)
	{
		arg->minpos = va_arg(*lst, int);
		if (arg->minpos < 0)
			arg->minpos = -2;
	}
	makearg(**s, &lst, &arg);
	return (arg);
}

int		printarg(t_arg *arg)
{
	int i;

	i = 0;
	if (arg->fstr != 1)
		i = ft_printd(arg);
	else
		i = printargstr(arg);
	return (i);
}

int		ft_printf(const char *form, ...)
{
	va_list valist;
	int		i;

	i = 0;
	va_start(valist, form);
	while (*form)
	{
		if (*form != '%' && ++i)
			write(1, form, 1);
		else
		{
			form++;
			i += printarg(getarg(&form, &valist));
		}
		form++;
	}
	return (i);
}
