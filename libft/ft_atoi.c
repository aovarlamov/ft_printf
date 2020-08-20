/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:11:00 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/17 03:01:41 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int	num;
	int				m;
	long long int	proof;

	proof = 0;
	num = 0;
	m = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		m = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		proof = num;
		num = num * 10 + (*str - '0');
		if (num / 10 != proof)
			return (m == -1 ? 0 : -1);
		str++;
	}
	return (num * m);
}
