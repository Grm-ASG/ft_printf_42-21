#include "ft_printf.h"

int				ft_print_str(char *str, t_fl *fl)
{
	int		s_len;
	char 	*tmp;
	int		res;

	if (!str)
		return (ft_print_str("(null)", fl));
	s_len = ft_strlen(str);
	if (fl->neg_star)
		fl->prec = -1;
	if (!(tmp = malloc(s_len)))
		return (-2);
	ft_strlcpy(tmp, str, s_len + 1);
	if (fl->prec != -1 && fl->prec < s_len)
	{
		tmp[fl->prec] = '\0';
		s_len = fl->prec;
	}
	res = ft_putchars(' ', fl->width - s_len, tmp, fl->pdn);
	free(tmp);
	tmp = NULL;
	return (res);
}
