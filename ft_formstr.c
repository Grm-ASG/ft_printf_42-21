/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:58:00 by imedgar           #+#    #+#             */
/*   Updated: 2020/07/18 20:17:56 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_print_str(char *str, t_fl *fl)
{
	char	*tmp;
	int		s_len;
	int		res;

	if (!str)
		return (ft_print_str("(null)", fl));
	s_len = ft_strlen(str);
//	if (fl->neg_star)
//		fl->prec = -1;
	if (!(tmp = malloc(s_len + 1)))
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
