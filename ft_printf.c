/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_printf.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: imedgar <imedgar@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2020/05/15 12:05:24 by imedgar		   #+#	  #+#			  */
/*	 Updated: 2020/05/19 11:02:09 by imedgar		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		factor;
	int			res;
	int			tmp;

	res = 0;
	va_start(factor, format);
	while (*format != '\0')
		if (*format != '%')
			res += ft_putchar(*format++);
		else
		{
			if ((tmp = ft_form_prnt(factor, &format)) == ERROR)
				break ;
			res += tmp;
		}
	va_end(factor);
	return (res);
}

int				ft_form_prnt(va_list factor, const char **format)
{
	const char	*str = *format;
	long long	star;
	t_fl		fl;

	fl.width = -1;
	fl.prec = -1;
	fl.pdn = 0;
	fl.neg_star = 0;
	fl.zer = 0;
	++str;
	while (*str && !(ft_strchr("cspdiuxX%", *str)))
	{
		if (*str == '-')
			fl.pdn = 1;
		else if (*str == '0')
			fl.zer = 1;
		else if (*str == '.')
			ft_prec(&str, factor, &fl);
		else if (*str == '*')
		{
			star = va_arg(factor, int);
			if (star < 0)
			{
				fl.pdn = 1;
				fl.neg_star = 1;
			}
			fl.width = star < 0 ? star * -1 : star;
		}
		else if (ft_isdigit(*str))
		{
			fl.width = ft_atoi(str);
			while (ft_isdigit(*(str + 1)))
				++str;
		}
		++str;
	}
	return (*str ? ft_type(&fl, str, factor, format) : ERROR);
}

void			ft_prec(const char **str, va_list factor, t_fl *fl)
{
	long long star;

	(*str)++;
	if (**str == '*')
	{
		star = va_arg(factor, int);
		if (star < 0)
			fl->neg_star = 1;
		fl->prec = star < 0 ? star * -1 : star;
	}
	else if (ft_isdigit(**str))
	{
		fl->prec = (size_t)ft_atoi(*str);
		while (ft_isdigit(*(*str + 1)))
			(*str)++;
	}
	else
	{
		fl->prec = 0;
		--(*str);
	}
}

int				ft_type(t_fl *fl, const char *str, \
						va_list factor, const char **format)
{
	const char	type = *str;
	int			res;

	res = 0;
	if (type == '%')
		res = ft_print_char('%', fl);
	else if (type == 'c')
		res = ft_print_char(va_arg(factor, int), fl);
	else if (type == 's')
		res = ft_print_str(va_arg(factor, char *), fl);
	else if (type == 'p')
		res = ft_print_adr((long long)va_arg(factor, void *), fl);
	else if (type == 'd' || type == 'i')
		res = ft_print_nbr(va_arg(factor, int), fl, 10, 0, type);
	else if (type == 'u')
		res = ft_print_nbr(va_arg(factor, unsigned int), fl, 10, 0, type);
	else if (type == 'x')
		res = ft_print_nbr(va_arg(factor, long), fl, 16, 0, type);
	else if (type == 'X')
		res = ft_print_nbr(va_arg(factor, long), fl, 16, 1, type);
	*format = ++str;
	return (res);
}
