#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef	struct	s_arg
{
	char	*arg;
	int	fpos;
	int	fzer;
	int	fstr;
	int	pos;
	int	minpos;
}		t_arg;

int ft_printf(const char *form, ...);
int makearg(char c, va_list **lst, t_arg **arg);
void printargstr(t_arg *arg);
#endif
