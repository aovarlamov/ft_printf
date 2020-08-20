/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:23:00 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/28 20:52:53 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_itoa_base(unsigned long long value, int base)
{
	int					i;
	char				*nbr;
	unsigned long long	tmp;

	i = 0;
	tmp = value;
	if (value == 0)
		return (ft_strdup("0"));
	while (tmp)
	{
		tmp /= base;
		i = i + 1;
	}
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	return (nbr);
}

char					*ft_itoa_base_low(unsigned long long value, int base)
{
	int					i;
	char				*nbr;
	unsigned long long	tmp;

	i = 0;
	tmp = value;
	if (value == 0)
		return (ft_strdup("0"));
	while (tmp)
	{
		tmp /= base;
		i = i + 1;
	}
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value = value / base;
	}
	return (nbr);
}

char					*ft_itoa_unsigned(unsigned long long int n)
{
	unsigned long long	tmp;
	unsigned long long	len;
	char				*res;

	len = 2;
	tmp = n;
	while ((tmp = tmp / 10))
		len++;
	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (0);
	res[--len] = '\0';
	while (len--)
	{
		res[len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

static int				ft_itoa_checkminus(intmax_t *n)
{
	int					minus;

	minus = 0;
	if (*n < 0)
	{
		*n = *n * -1;
		minus = 1;
	}
	return (minus);
}

char					*ft_itoa(intmax_t n)
{
	intmax_t			tmp;
	intmax_t			len;
	char				*res;
	int					m;

	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	len = 2;
	m = ft_itoa_checkminus(&n);
	tmp = n;
	while ((tmp = tmp / 10))
		len++;
	len += m;
	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (0);
	res[--len] = '\0';
	while (len--)
	{
		res[len] = n % 10 + '0';
		n /= 10;
	}
	if (m == 1)
		res[0] = '-';
	return (res);
}
