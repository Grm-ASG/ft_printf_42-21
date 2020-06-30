/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 13:55:44 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/18 14:48:57 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

# define ERROR -2

typedef struct	s_fl
{
	char		pdn;
	char		zer;
	long long	prec;
	long long	width;
}				t_fl;

int				ft_printf(const char *format, ...);
int				ft_print_char(char c, t_fl *fl);
int				ft_form_prnt(va_list factor, const char **format);
void			ft_prec(const char **str, va_list factor, t_fl *fl);
int				ft_type(t_fl *fl, const char *str, \
						va_list factor, const char **format);
int				ft_putchars(char c, int nbr);
int				ft_print_str(char *str, t_fl *fl);

#endif
