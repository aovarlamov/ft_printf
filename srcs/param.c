/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:04:32 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/28 20:26:07 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param			*ft_newparam(const char *str, int count)
{
	t_param		*res;

	res = (t_param *)malloc(sizeof(t_param));
	if (res)
	{
		res->flag_m = param_flag_minus(str, count);
		res->flag_p = param_flag_plus(str, count);
		res->flag_s = param_flag_space(str, count);
		res->flag_h = param_flag_hash(str, count);
		res->flag_n = param_flag_null(str, count);
		res->width = param_width(str, count);
		res->precis = param_precision(str, count);
		res->modif = param_modifier(str, count);
		res->conver = param_conversion(str, count);
		return (res);
	}
	else
		ft_delparam(&res);
	return (NULL);
}

void			ft_delparam(t_param **param)
{
	t_param		*temp;

	temp = *param;
	temp->flag_m = 0;
	temp->flag_p = 0;
	temp->flag_s = 0;
	temp->flag_h = 0;
	temp->flag_n = 0;
	temp->width = 0;
	temp->precis = 0;
	ft_strdel(&temp->modif);
	temp->conver = 0;
	free(temp);
	*param = NULL;
}
