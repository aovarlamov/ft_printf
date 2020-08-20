/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:09:38 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/29 11:21:41 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			prf_putstr(const char *str, int count)
{
	int		i;

	i = 0;
	while (i < count)
		write(1, &str[i++], 1);
	return (count);
}

int			prf_putparam(t_param *param, va_list ap)
{
	if (param->conver == 'd' || param->conver == 'i')
		return (print_d_i(param, ap));
	if (param->conver == 'u')
		return (print_u(param, ap));
	if (param->conver == 'o')
		return (print_o(param, ap));
	if (param->conver == 'x')
		return (print_x(param, ap));
	if (param->conver == 'X')
		return (print_bx(param, ap));
	if (param->conver == '%')
		return (print_proc(param));
	if (param->conver == 'c')
		return (print_c(param, ap));
	if (param->conver == 's')
		return (print_s(param, ap));
	if (param->conver == 'p')
		return (print_p(param, ap));
	if (param->conver == 'f')
		return (print_f(param, ap));
	return (0);
}
