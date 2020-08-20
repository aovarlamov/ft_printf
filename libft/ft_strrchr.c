/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:41:31 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/16 22:01:53 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	int	i;

	if (to_find == '\0')
		return ((char *)str + ft_strlen(str));
	i = ft_strlen(str);
	while (--i >= 0)
	{
		if (str[i] == to_find)
			return ((char *)str + i);
	}
	return (0);
}
