/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:54:26 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/31 10:49:49 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				prf_writer(const char *str, int count, va_list ap)
{
	t_param		*param;
	int			count_param;

	param = NULL;
	if (*str == '%')
	{
		param = ft_newparam(str, count);
		count_param = prf_putparam(param, ap);
		ft_delparam(&param);
		return (count_param);
	}
	else
		return (prf_putstr(str, count));
}

int				prf_check_param(const char *str, int *i)
{
	while (!prf_chk_conversion(str[*i]) && (prf_chk_flag(str[*i]) ||
	prf_chk_digit(str[*i]) || prf_chk_precision(str[*i]) ||
	prf_chk_modifier(str[*i])) && str[*i])
		*i += 1;
	if (prf_chk_conversion(str[*i]) && str[*i])
	{
		*i += 1;
		return (1);
	}
	else
		return (0);
}

int				prf_parser(char const *str, va_list ap)
{
	int			i;
	int			start;
	int			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		start = i;
		if (str[i] == '%')
		{
			i++;
			if (prf_check_param(str, &i))
				count += prf_writer(str + start, i - start, ap);
		}
		else
		{
			while (str[i] != '%' && str[i])
				i++;
			count += prf_writer(str + start, i - start, ap);
		}
	}
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, format);
	count = prf_parser(format, ap);
	va_end(ap);
	return (count);
}
