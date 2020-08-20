/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:40:36 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/29 11:21:22 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_proc(t_param *param)
{
	char	*x;
	size_t	len;

	len = 1;
	x = ft_strnew(1);
	x[0] = '%';
	if (param->width > len)
		x = width_change(x, param, &len);
	ft_putstr(x);
	ft_strdel(&x);
	return (len);
}
