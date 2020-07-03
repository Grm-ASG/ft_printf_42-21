#include "ft_printf.h"

int				ft_print_nbr(int adr, t_fl *fl)
{
	char	*num;
	char	tmp[32];
	int		res;
	int		len;

	if (!(num = ft_itoa_base(adr, 10, 0)))
		return (-2);
	len = ft_strlen(num);
	res = 0;
	ft_strlcpy(tmp, num, len + 1);
	res += ft_putchars(' ', fl->width - len, tmp, fl->pdn);
	free(num);
	num = NULL;
	return (res);
}
