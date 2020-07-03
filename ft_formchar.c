#include "ft_printf.h"

int				ft_print_char(char c, t_fl *fl)
{
	int		res;
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	res = 0;
	if (fl->width > 1)
	{
		if (c == '\0' && fl->pdn)
			res += ft_putchar(c);
		res += ft_putchars(' ', fl->width - 1, str, fl->pdn);
		if (c == '\0' && !fl->pdn)
			res += ft_putchar(c);
	}
	else
		res = ft_putchar(c);
	return (res);
}
