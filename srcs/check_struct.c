/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:58:58 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/28 17:11:30 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prf_chk_flag(char c)
{
	if (ft_strchr("-+ #0", c))
		return (1);
	else
		return (0);
}

int		prf_chk_digit(char c)
{
	if (ft_strchr("123456789", c))
		return (1);
	else
		return (0);
}

int		prf_chk_precision(char c)
{
	if (ft_strchr(".", c))
		return (1);
	else
		return (0);
}

int		prf_chk_modifier(char c)
{
	if (ft_strchr("hlL", c))
		return (1);
	else
		return (0);
}

int		prf_chk_conversion(char c)
{
	if (ft_strchr("dDioOuxXefFcCsSp%", c))
		return (1);
	else
		return (0);
}
