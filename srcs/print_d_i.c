/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:18:08 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/29 19:25:45 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_d_i(t_param *param, va_list ap)
{
	char		*x;
	intmax_t	n;

	if (param->modif == NULL)
		n = va_arg(ap, int);
	else if (ft_strcmp(param->modif, "ll") == 0)
		n = va_arg(ap, long long);
	else if (ft_strcmp(param->modif, "l") == 0)
		n = va_arg(ap, long);
	else if (ft_strcmp(param->modif, "hh") == 0)
	{
		n = va_arg(ap, int);
		n = (signed char)n;
	}
	else
	{
		n = va_arg(ap, int);
		n = (short)n;
	}
	x = ft_itoa(n);
	return (print_d_i_changer(param, x, n));
}

int				print_d_i_changer(t_param *param, char *x, intmax_t n)
{
	size_t		len;

	len = ft_strlen(x);
	if (param->precis + 1 > (int)len || (param->precis == -1 && n == 0))
		x = precision_change(x, param, &len);
	if (param->width > len)
		x = width_change(x, param, &len);
	if (param->flag_p)
		x = flag_plus_wr(x, param, &len);
	if (param->flag_s && ft_strchr(x, '+') == 0)
		x = flag_space_wr(x, param, &len);
	ft_putstr(x);
	ft_strdel(&x);
	return (len);
}
