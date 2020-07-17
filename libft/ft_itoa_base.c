/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:01:40 by imedgar           #+#    #+#             */
/*   Updated: 2020/07/17 21:01:41 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_hlpr(long long val, char base, int *size, char *neg)
{
	long long int	tmp;
	char			*res;

	*size = 1;
	*neg = (base == 10 && val < 0) ? 1 : 0;
	tmp = val < 0 ? val * -1 : val;
	while (tmp /= base)
		*size += 1;
	if (!(res = (char *)malloc(*size + 1 + *neg)))
		return (NULL);
	return (res);
}

char			*ft_itoa_base(long long val, char base, char sign)
{
	const char		base_str[] = "0123456789abcdef";
	char			*res;
	char			ltr;
	char			neg;
	int				size;

	if (!(res = ft_hlpr(val, base, &size, &neg)))
		return (NULL);
	if (val == 0)
		res[0] = '0';
	if (neg)
	{
		res[0] = '-';
		val *= -1;
	}
	res[size + neg] = '\0';
	while (val)
	{
		ltr = base_str[val % base];
		res[--size + neg] = (sign && ltr > '9') ? ltr - 32 : ltr;
		val /= base;
	}
	return (res);
}
