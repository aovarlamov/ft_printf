/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:24:53 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/29 16:07:41 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*flag_plus_wr(char *x, t_param *param, size_t *len)
{
	int			i;
	int			j;
	char		*str;

	if (ft_strchr(x, '-'))
		return (x);
	else
		*len = *len + 1;
	str = ft_strnew(*len);
	i = *len - 1;
	j = *len - 2;
	while (j != -1)
	{
		str[i] = x[j];
		if (!param->flag_m && (x[j] == ' ' || x[j] == '+'))
			break ;
		j--;
		i--;
	}
	str[i--] = '+';
	while (i >= 0)
		str[i--] = ' ';
	ft_strdel(&x);
	return (str);
}

char			*flag_space_wr(char *x, t_param *param, size_t *len)
{
	int			i;
	int			j;
	char		*str;

	if (ft_strchr(x, '-'))
		return (x);
	else
		*len = *len + 1;
	str = ft_strnew(*len);
	i = *len - 1;
	j = *len - 2;
	while (j != -1)
	{
		str[i] = x[j];
		if (!param->flag_m && (x[j] == ' ' || x[j] == '+'))
			break ;
		j--;
		i--;
	}
	while (i >= 0)
		str[i--] = ' ';
	ft_strdel(&x);
	return (str);
}

char			*ft_add_h(char *x, t_param *param, size_t *len)
{
	char		*res;
	int			i;

	*len = *len + 2;
	res = ft_strnew(*len);
	i = 2;
	res[0] = '0';
	if (param->conver == 'X')
		res[1] = 'X';
	else
		res[1] = 'x';
	while (x[i - 2])
	{
		res[i] = x[i - 2];
		i++;
	}
	param->flag_h = 0;
	ft_strdel(&x);
	return (res);
}

char			*ft_add_0(char *x, t_param *param, size_t *len)
{
	char		*res;
	int			i;

	*len = *len + 1;
	res = ft_strnew(*len);
	i = 1;
	res[0] = '0';
	while (x[i - 1])
	{
		res[i] = x[i - 1];
		i++;
	}
	param->flag_h = 0;
	ft_strdel(&x);
	return (res);
}

char			*ft_add_point(char *x, t_param *param, size_t *len)
{
	char		*res;
	int			i;
	int			j;

	if (*len < param->width)
		*len = param->width;
	res = ft_strnew(*len);
	j = 0;
	i = 0;
	while (x[i] == ' ')
		res[i++] = x[j++];
	while (x[i] == '+' || x[i] == '-' || (x[i] >= '0' && x[i] <= '9'))
		res[i++] = x[j++];
	res[i++] = '.';
	j++;
	while (i < (int)*len && x[j])
		res[i++] = x[j++];
	while (i < (int)*len)
		res[i++] = ' ';
	ft_strdel(&x);
	return (res);
}
