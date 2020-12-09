/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:39:20 by rcaraway          #+#    #+#             */
/*   Updated: 2020/12/09 14:45:48 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef	struct	s_arg
{
	int			fposzer;
	char		*arg;
	int			fpos;
	int			fzer;
	int			fstr;
	int			fnul;
	int			pos;
	int			minpos;
	int			ffree;
}				t_arg;

void			getform2(const char ***s, t_arg **arg);
int				ft_printf(const char *form, ...);
int				makearg(char c, va_list **lst, t_arg **arg);
int				printargstr(t_arg *arg);
int				ft_printd(t_arg *arg);
void			makenode(t_arg **arg);
char			*getpointer(void *s);
int				makearg3(char c, va_list **lst, t_arg **arg);
int				printargstr2(t_arg *arg, int i, int j);
int				isarg(char c);
#endif
