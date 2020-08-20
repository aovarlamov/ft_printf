/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:34:48 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/29 19:14:30 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_u(t_param *param, va_list ap)
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
		n = va_arg(ap, int);
		n = (unsigned char)n;
	}
	else
		n = va_arg(ap, unsigned int);
	x = ft_itoa_base(n, 10);
	return (print_u_changer(param, x));
}

int			print_u_changer(t_param *param, char *x)
{
	size_t		len;

	len = ft_strlen(x);
	if (param->precis > (int)len || param->precis == -1)
		x = precision_change(x, param, &len);
	if (param->width > len)
		x = width_change(x, param, &len);
	ft_putstr(x);
	ft_strdel(&x);
	return (len);
}
