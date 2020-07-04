#include "ft_printf.h"

static char		*ft_nbr(char *num, int len, int prec)
{
	long long	size;
	char		*new;
	int			i;
	int			j;

	size = *num == '-' ? prec + 2 : prec + 1;
	if (!(new = malloc(size)))
	{
		free(num);
		return (NULL);
	}
	i = 0;
	j = 0;
	new[size - 1] = '\0';
	if (num[i] == '-' && len--)
		new[i++] = num[j++];
	while (prec-- > len)
		new[i++] = '0';
	while (len--)
		new[i++] = num[j++];
	free(num);
	return (new);
}

int				ft_print_nbr(int adr, t_fl *fl)
{
	char	*num;
	int		res;
	int		len;

	if (!(num = ft_itoa_base(adr, 10, 0)))
		return (-2);
	len = ft_strlen(num);
	if (fl->prec > len)
		if (!(num = ft_nbr(num, len, fl->prec)))
			return (-2);
	if (fl->prec == 0)
		num[0] = 0;
	len = ft_strlen(num);
	res = ft_putchars(' ', fl->width - len, num, fl->pdn);
	free(num);
	return (res);
}
