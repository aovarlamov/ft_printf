/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:05:18 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/29 11:56:35 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			param_flag_minus(const char *str, int count)
{
	if (ft_strnchr(str, '-', count))
		return (1);
	else
		return (0);
}

int			param_flag_plus(const char *str, int count)
{
	if (ft_strnchr(str, '+', count))
		return (1);
	else
		return (0);
}

int			param_flag_space(const char *str, int count)
{
	if (ft_strnchr(str, ' ', count))
		return (1);
	else
		return (0);
}

int			param_flag_hash(const char *str, int count)
{
	if (ft_strnchr(str, '#', count))
		return (1);
	else
		return (0);
}

int			param_flag_null(const char *str, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (str[i - 1] != '.' && str[i] == '0' && (str[i - 1] < '0' ||
		str[i - 1] > '9'))
			return (1);
		i++;
	}
	return (0);
}
