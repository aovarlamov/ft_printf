/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:24:14 by kbethel           #+#    #+#             */
/*   Updated: 2020/01/28 18:07:45 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnchr(const char *str, int to_find, int n)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	if (to_find == '\0')
		return ((char *)str + ft_strlen(str));
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == to_find)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
