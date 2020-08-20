/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:10:50 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/29 16:04:15 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*width_change(char *x, t_param *param, size_t *len)
{
	char	*str;
	int		j;

	if ((param->flag_p || param->flag_s || param->flag_h) && *x != '-' &&
	*x != '+' && (param->conver == 'd' || param->conver == 'f'))
		j = param->width - 1;
	else if (param->flag_h && *x != '0' && *x != '\0' &&
	(param->conver == 'P' || param->conver == 'X' || param->conver == 'x'))
		j = param->width - 2;
	else
		j = param->width;
	str = ft_strnew(j);
	*len = j;
	if (param->flag_m)
		str = width_change_left(str, x, j);
	else
		str = width_change_right(str, x, j, param);
	ft_strdel(&x);
	return (str);
}

char		*width_change_left(char *str, char *x, int j)
{
	int		i;

	i = 0;
	while (*x)
	{
		str[i] = *x;
		x++;
		i++;
	}
	while (i < j)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}

char		*width_change_right(char *str, char *x, int j, t_param *param)
{
	int		i;
	int		len_x;

	i = 0;
	if (x[0] == '-' && param->flag_n && (param->precis > j ||
	(param->flag_n && param->precis == 0) || param->conver == 'f'))
		str[i++] = *x++;
	len_x = (int)ft_strlen(x);
	while (i < (j - len_x))
	{
		if (param->flag_n && (param->precis == 0 || param->conver == 'f'))
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	while (i < j)
		str[i++] = *x++;
	return (str);
}

char		*precision_change(char *x, t_param *param, size_t *len)
{
	char	*str;

	if (param->precis == -1)
	{
		*len = 0;
		return (ft_strdup(""));
	}
	str = precision_change_work(x, param, len);
	*len = param->precis;
	ft_strdel(&x);
	return (str);
}

char		*precision_change_work(char *x, t_param *param, size_t *len)
{
	int		i;
	char	*str;

	i = 0;
	if (*x == '-' || *x == '+')
		param->precis = param->precis + 1;
	str = ft_strnew(param->precis);
	if (*x == '-' || *x == '+')
	{
		str[i++] = *x++;
		*len = *len - 1;
	}
	while (i < (param->precis - (int)*len))
		str[i++] = '0';
	while (i < param->precis)
		str[i++] = *x++;
	return (str);
}
