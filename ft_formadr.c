#include "ft_printf.h"

int				ft_print_adr(long long adr, t_fl *fl)
{
	char	*num;
	char	tmp[32];
	int		res;
	int		len;

	if (!(num = ft_itoa_base(adr, 16, 0)))
		return (-2);
	len = ft_strlen(num) + 2;
	res = 0;
	tmp[0] = '0';
	tmp[1] = 'x';
	ft_strlcpy(tmp + 2, num, len);
	res += ft_putchars(' ', fl->width - len, tmp, fl->pdn);
	free(num);
	num = NULL;
	return (res);
}
