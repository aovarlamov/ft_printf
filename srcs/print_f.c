/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:45:56 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/31 10:19:14 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_f(t_param *param, va_list ap)
{
	char		*x;
	long double	f;

	if (param->modif == NULL || ft_strcmp(param->modif, "l") == 0 ||
	ft_strcmp(param->modif, "ll") == 0 || ft_strcmp(param->modif, "h") == 0
	|| ft_strcmp(param->modif, "hh") == 0)
		f = va_arg(ap, double);
	else
		f = va_arg(ap, long double);
	if (!param->precis)
		param->precis = 6;
	x = ft_ftoa_prf(f, param);
	return (print_f_changer(param, x));
}

int				print_f_changer(t_param *param, char *x)
{
	size_t		len;

	len = ft_strlen(x);
	if (param->width > len)
		x = width_change(x, param, &len);
	if (param->flag_p)
		x = flag_plus_wr(x, param, &len);
	if (param->flag_s && param->flag_p == 0)
		x = flag_space_wr(x, param, &len);
	if (param->flag_h)
		x = ft_add_point(x, param, &len);
	ft_putstr(x);
	ft_strdel(&x);
	return (len);
}
