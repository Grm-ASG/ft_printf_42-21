#include "ft_printf.h"

int				ft_print_char(char c, t_fl *fl)
{
	int res;

	if (fl->width > 1)
		if (fl->pdn)
		{
			res = ft_putchar(c);
			res += ft_putchars(' ', fl->width);
		}
		else
		{
			res = ft_putchars(' ', fl->width);
			res += ft_putchar(c);
		}
	else
		res = ft_putchar(c);
	return (res);
}
