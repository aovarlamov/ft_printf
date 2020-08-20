/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:36:51 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/29 19:14:21 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_o(t_param *param, va_list ap)
{
	char				*x;
	uintmax_t			n;

	if (param->modif == NULL)
		n = va_arg(ap, unsigned int);
	else if (ft_strcmp(param->modif, "ll") == 0)
		n = va_arg(ap, unsigned long long);
	else if (ft_strcmp(param->modif, "l") == 0)
		n = va_arg(ap, unsigned long);
	else if (ft_strcmp(param->modif, "hh") == 0)
	{
		n = va_arg(ap, unsigned int);
		n = (unsigned char)n;
	}
	else
	{
		n = va_arg(ap, unsigned int);
		n = (unsigned short)n;
	}
	x = ft_itoa_base_low(n, 8);
	return (print_o_changer(param, x, n));
}

int			print_o_changer(t_param *param, char *x, uintmax_t n)
{
	size_t		len;

	len = ft_strlen(x);
	if (param->precis > (int)len || (param->precis == -1 && param->flag_h != 1))
		x = precision_change(x, param, &len);
	if (param->flag_h && *x != '0' && (param->flag_n == 0 ||
	(param->precis < (int)param->width && param->precis != 0)))
		x = ft_add_0(x, param, &len);
	if (param->width > len)
		x = width_change(x, param, &len);
	if (param->flag_h && *x != '0' && n != 0 && (param->precis == 0
	|| param->precis == (int)param->width))
		x = ft_add_0(x, param, &len);
	ft_putstr(x);
	ft_strdel(&x);
	return (len);
}
