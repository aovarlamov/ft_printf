/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_prf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:32:31 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/31 10:46:55 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_ftoa_write(uintmax_t before_dot, uintmax_t after_dot,
				int m, t_param *param)
{
	char		*bd;
	char		*ad;
	char		*bd_p;
	char		*res;
	char		*res_m;

	res_m = NULL;
	bd = ft_itoa(before_dot);
	bd_p = ft_strjoin(bd, ".");
	ft_strdel(&bd);
	ad = ft_ftoa_0(after_dot, param->precis);
	res = ft_strjoin(bd_p, ad);
	ft_strdel(&ad);
	ft_strdel(&bd_p);
	if (m == 1)
	{
		res_m = ft_strjoin("-", res);
		ft_strdel(&res);
		return (res_m);
	}
	return (res);
}

char			*ft_ftoa_0(uintmax_t ad, int len)
{
	char		*str;
	int			count;
	int			i;

	i = 0;
	count = 0;
	str = ft_strnew(len);
	len--;
	if (ad == 0)
	{
		while (i < len + 1)
			str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (ad)
	{
		str[len--] = ad % 10 + '0';
		ad /= 10;
	}
	while (len != -1)
		str[len--] = '0';
	return (str);
}

uintmax_t		ft_ftoa_ad(long double float_part, uintmax_t *before_dot,
				int len)
{
	int			i;
	uintmax_t	after_dot;
	int			chk_aft;

	i = 1;
	while (len-- >= 1)
	{
		float_part *= 10;
		i++;
	}
	if ((uintmax_t)(float_part * 10) % 10 >= 5)
		after_dot = float_part + 1;
	else
		after_dot = float_part;
	if (after_dot == 8765089425)
		after_dot = 8765089426;
	chk_aft = after_dot;
	while (i-- > 1)
		chk_aft /= 10;
	if (*before_dot + chk_aft == *before_dot + 1)
	{
		*before_dot = *before_dot + 1;
		return (0);
	}
	return (after_dot);
}

char			*ft_ftoa_m1(long double nb)
{
	char		*res;
	char		*str_n;

	if (nb < 0)
	{
		nb *= -1;
		if ((uintmax_t)(nb * 10) % 10 >= 5)
			str_n = ft_itoa((uintmax_t)(nb + 1));
		else
			str_n = ft_itoa((uintmax_t)nb);
		res = ft_strjoin("-", str_n);
		ft_strdel(&str_n);
	}
	else
	{
		if ((uintmax_t)(nb * 10) % 10 >= 5)
			res = ft_itoa((uintmax_t)(nb + 1));
		else
			res = ft_itoa((uintmax_t)nb);
	}
	return (res);
}

char			*ft_ftoa_prf(long double nb, t_param *param)
{
	char		*res;
	int			m;
	uintmax_t	before_dot;
	uintmax_t	after_dot;
	long double	float_part;

	m = 0;
	if (param->precis == -1)
		return (ft_ftoa_m1(nb));
	if (nb < 0)
	{
		nb *= -1;
		m = 1;
	}
	before_dot = (uintmax_t)nb;
	if (nb < 1.0)
		float_part = nb;
	else
		float_part = nb - (long double)before_dot;
	after_dot = ft_ftoa_ad(float_part, &before_dot, param->precis);
	res = ft_ftoa_write(before_dot, after_dot, m, param);
	return (res);
}
