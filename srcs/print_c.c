/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:16:01 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/29 15:48:12 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_c(t_param *param, va_list ap)
{
	char	*x;
	size_t	len;

	x = ft_strnew(1);
	len = 1;
	x[0] = va_arg(ap, int);
	if (x[0] == 0)
		return (print_c_null(param, len, x));
	if (param->width > ft_strlen(x))
		x = width_change(x, param, &len);
	ft_putstr(x);
	ft_strdel(&x);
	return (len);
}

int			print_c_null(t_param *param, size_t len, char *x)
{
	if (param->width == 0)
	{
		ft_putchar(0);
		return (1);
	}
	else
		param->width -= 1;
	x = width_change(x, param, &len);
	if (param->flag_m == 1)
	{
		ft_putchar(0);
		ft_putstr(x);
		ft_strdel(&x);
	}
	else
	{
		ft_putstr(x);
		ft_strdel(&x);
		ft_putchar(0);
	}
	return (len + 1);
}
