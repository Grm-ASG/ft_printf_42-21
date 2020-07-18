/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:57:30 by imedgar           #+#    #+#             */
/*   Updated: 2020/07/18 19:55:33 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		num = NULL;
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
	num = NULL;
	return (new);
}

static char		*ft_zer(char *num, int len, int width, t_fl *fl)
{
	char	*new;
	int		i;
	int		j;

	if (fl->prec < len && fl->prec != -1)
		return (num);
	if (!(new = malloc(width + 1)))
	{
		free(num);
		num = NULL;
		return (NULL);
	}
	new[width] = '\0';
	i = 0;
	j = 0;
	if (num[i] == '-')
		new[i++] = num[j++];
	while (width-- > len)
		new[i++] = '0';
	while (len--)
		new[i++] = num[j++];
	free(num);
	num = NULL;
	return (new);
}

int				ft_print_nbr(size_t adr, t_fl *fl, char base, char x)
{
	char	*num;
	int		res;
	int		len;

	if (fl->neg_star)
		fl->prec = -1;
	if (!(num = ft_itoa_base(adr, base, x)))
		return (-2);
	if (fl->type == 'i' && fl->zer && fl->prec != -1)
		fl->zer = 0;
	len = ft_strlen(num);
	if (fl->prec > len)
	{
		if (!(num = ft_nbr(num, len, fl->prec)))
			return (-2);
	}
	else if (fl->zer && !fl->pdn && fl->width > len)
		if (!(num = ft_zer(num, len, fl->width, fl)))
			return (-2);
	if (fl->prec == 0 && num[0] == '0')
		num[0] = 0;
	res = ft_putchars(' ', fl->width - ft_strlen(num), num, fl->pdn);
	free(num);
	num = NULL;
	return (res);
}
