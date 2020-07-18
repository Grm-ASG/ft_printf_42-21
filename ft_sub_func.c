/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:32:04 by imedgar           #+#    #+#             */
/*   Updated: 2020/07/18 20:56:22 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_init(t_fl *fl)
{
	fl->width = -1;
	fl->prec = -1;
	fl->pdn = 0;
	fl->neg_width = 0;
	fl->neg_prec = 0;
	fl->zer = 0;
}

long long		ft_star_width(long long star, t_fl *fl)
{
	if (star < 0)
	{
		fl->pdn = 1;
		fl->neg_width = 1;
	}
	return (star < 0 ? star * -1 : star);
}
