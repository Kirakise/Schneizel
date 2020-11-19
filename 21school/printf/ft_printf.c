/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:52:43 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/19 15:52:25 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int isarg(char c)
{
	const char *s = "cspdiuxX";
	while (*s != c && *s)
		s++;
	if (!*s)
		return (1);
	return (0);
}

void getform(const char ***s, t_arg **arg)
{
	(*arg)->fpos = 0;
	(*arg)->fzer = 0;
	(*arg)->minpos = -2;
	(*arg)->pos = -2;
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
	else if(***s == '*')
		(*arg)->pos = -1;
	while (***s != '.' && isarg(***s))
			(**s)++;
	if (***s == '.' && (**s)++)
	{
		if (***s == '*')
			(*arg)->minpos = -1;
		else
			(*arg)->minpos = ft_atoi(**s);
	}
	while (isarg(***s))
		(**s)++;
}

t_arg *getarg(const char **s, va_list *lst)
{
	t_arg *arg;

	if (!(arg = malloc(sizeof(struct s_arg))))
		return (NULL);
	getform(&s, &arg);
	if (arg->pos == -1)
	{
		arg->pos = va_arg(*lst, int);
		if (arg->pos < 0)
			arg->pos = -2;
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

void printarg(t_arg *arg)
{
	if (arg->fstr == 0)
	{
		arg->pos -= ft_strlen(arg->arg) > arg->minpos ?
			ft_strlen(arg->arg) : arg->minpos;
		arg->minpos -= ft_strlen(arg->arg);
		if (arg->fpos == 0)
		{
			while(arg->pos-- > 0)
				write(1, " ", 1);
			while(arg->minpos-- > 0)
				write(1, "0", 1);
			ft_putstr_bonus(arg->arg);
		}
		else
		{
			while(arg->minpos-- > 0)
				write(1, "0", 1);
			ft_putstr_bonus(arg->arg);
			while(arg->pos-- > 0)
				write(1, " ", 1);
		}
		free(arg->arg);
		free(arg);
	}
	else
		printargstr(arg);
}

int	ft_printf(const char *form, ...)
{
	va_list valist;
	va_start(valist, form);
	while(*form)
	{
		if (*form != '%')
			write(1, form, 1);
		else if(*(form + 1) == '%')
			write(1, ++form, 1);
		else
		{
			form++;
			printarg(getarg(&form, &valist));
		}
		form++;
	}
	return (0);
}
