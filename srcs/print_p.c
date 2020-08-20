/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:12:08 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/28 20:34:08 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_p(t_param *param, va_list ap)
{
	char	*x;
	size_t	len;

	x = ft_itoa_base_low(va_arg(ap, long long), 16);
	len = ft_strlen(x);
	if (param->precis > (int)len || param->precis == -1)
		x = precision_change(x, param, &len);
	x = ft_add_h(x, param, &len);
	if (param->width > len)
		x = width_change(x, param, &len);
	ft_putstr(x);
	ft_strdel(&x);
	return (len);
}
