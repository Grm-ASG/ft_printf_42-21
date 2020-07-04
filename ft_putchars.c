#include "ft_printf.h"

int				ft_putchars(char c, int nbr, char *str, char pdn)
{
	int res;
	int i;

	i = 0;
	res = 0;
	if (pdn)
	{
		res = ft_putstr(str);
		while (i++ < nbr)
			res += ft_putchar(c);
	}
	else
	{
		while (i++ < nbr)
			res += ft_putchar(c);
		res += ft_putstr(str);
	}
	return (res);
}
