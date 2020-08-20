/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:31:50 by kbethel           #+#    #+#             */
/*   Updated: 2019/11/04 18:04:16 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	if (to_find == '\0')
		return ((char *)str + ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
			return ((char *)str + (i + 1));
		i++;
	}
	return (0);
}
