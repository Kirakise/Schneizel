#include "libft.h"
#include "ft_printf.h"


char *getpointer(void *s)
{
	size_t tmp = (unsigned long long)s;
	char *s1 = ft_itoax_bonus(tmp, 0);
	return (s1);
}
int makearg2(char c, va_list **lst, t_arg **arg)
{
	if (c == 'd' || c == 'i' || c == 'u')
	{
		if (!((*arg)->arg = ft_itoa(va_arg(**lst, int))))
		{
			free(*arg);
			return (0);
		}
	}
	else if (c == 'x')
	{
		if (!((*arg)->arg = ft_itoax_bonus(va_arg(**lst, int), 0)))
		{
			free(*arg);
			return (0);
		}
	}
	else if (c == 'X')
	{
		if (!((*arg)->arg = ft_itoax_bonus(va_arg(**lst, int), 1)))
		{
			free(*arg);
			return (0);
		}
	}
	return (1);
}
int makearg(char c, va_list **lst, t_arg **arg)
{
	if (c == 'c')
	{
		if(!((*arg)->arg = malloc(2)))
		{
			free(*arg);
			return (0);
		}
		(*arg)->arg[0] = va_arg(**lst, int);
		(*arg)->arg[1] = '\0';
		(*arg)->fstr = 1;
	}
	else if (c == 's')
	{
		(*arg)->arg = va_arg(**lst, char *);
		(*arg)->fstr = 1;
	}
	else if (c == 'p')
		if (!((*arg)->arg = getpointer(va_arg(**lst, void *))))
		{
			free(*arg);
			return (0);
		}
	return(makearg2(c, lst, arg));
}

void printargstr(t_arg *arg)
{
	int i;

	i = 0;
	if (arg->arg == 0)
		arg->arg = "(null)";
	arg->minpos = arg->minpos == -2 ? ft_strlen(arg->arg) : arg->minpos;
	if (arg->fpos == 0)
	{
		arg->pos -= ft_strlen(arg->arg) > arg->minpos ? arg->minpos : ft_strlen(arg->arg);
		while (arg->pos-- > 0)
			write(1, " ", 1);
		while(arg->arg[i] && i < arg->minpos)
			write(1, &(arg->arg[i++]), 1);
	}
	else
	{
		while(arg->arg[i] && i < arg->minpos)
			write(1, &(arg->arg[i++]), 1);
		while(i++ < arg->pos)
			write(1, " ", 1);
	}
}
