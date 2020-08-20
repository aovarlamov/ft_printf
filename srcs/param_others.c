/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:10:44 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/29 19:36:28 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			param_width(const char *str, int count)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	while (i < count && (str[i] < 49 || str[i] > 57))
		i++;
	if (str[i] >= '1' && str[i] <= '9' && i < count && str[i - 2] != '.' &&
	str[i - 1] != '.')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			width = width * 10 + (str[i] - '0');
			i++;
		}
		return (width);
	}
	else
		return (0);
}

int			param_precision(const char *str, int count)
{
	int		i;
	int		precision;

	i = 0;
	precision = 0;
	while (i < count && str[i] != '.')
		i++;
	if (str[i] == '.' && i < count)
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			precision = precision * 10 + (str[i] - '0');
			i++;
		}
		if (precision == 0)
			return (-1);
		else
			return (precision);
	}
	else
		return (0);
}

char		*param_modifier(const char *str, int count)
{
	if (ft_strnstr(str, "ll", count))
		return (ft_strdup("ll"));
	if (ft_strnstr(str, "l", count))
		return (ft_strdup("l"));
	if (ft_strnstr(str, "hh", count))
		return (ft_strdup("hh"));
	if (ft_strnstr(str, "h", count))
		return (ft_strdup("h"));
	if (ft_strnstr(str, "LL", count))
		return (NULL);
	if (ft_strnstr(str, "L", count))
		return (ft_strdup("L"));
	return (NULL);
}

char		param_conversion(const char *str, int count)
{
	int		i;

	i = 1;
	while (!prf_chk_conversion(str[i]) && i < count)
		i++;
	if (str[i] == 'D')
		return ('d');
	if (str[i] == 'O')
		return ('o');
	if (str[i] == 'C')
		return ('c');
	if (str[i] == 'i')
		return ('d');
	if (str[i] == 'F')
		return ('f');
	return (str[i]);
}
