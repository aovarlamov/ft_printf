/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:24:55 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/29 14:34:26 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_s(t_param *param, va_list ap)
{
	char	*x;
	char	*x1;
	size_t	len;

	x1 = va_arg(ap, char *);
	if (!x1)
		return (print_s_null(param, x1));
	x = ft_strdup(x1);
	len = ft_strlen(x);
	if (param->precis < (int)len && param->precis != 0)
		x = precision_change(x, param, &len);
	if (param->width > ft_strlen(x))
		x = width_change(x, param, &len);
	ft_putstr(x);
	ft_strdel(&x);
	return (len);
}

int			print_s_null(t_param *param, char *x)
{
	size_t	len;

	len = 6;
	x = ft_strdup("(null)");
	if (param->precis < (int)len && param->precis != 0)
		x = precision_change(x, param, &len);
	if (param->width > len)
		x = width_change(x, param, &len);
	ft_putstr(x);
	ft_strdel(&x);
	return (len);
}
