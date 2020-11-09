/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:52:43 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/09 16:52:32 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>

void printarg(const char **s, ...)
{
	va_list valist;
	va_start(valist, getparams(*s));

}

int	ft_printf(const char *form, ...)
{
	va_list valist;
	va_start(valist, form);
	while(*from)
	{
		while(*form != '%')
			write(1, form++, 1);
		
	}
}
