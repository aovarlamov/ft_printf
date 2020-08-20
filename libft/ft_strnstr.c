/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:51:23 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/17 18:29:03 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int i;
	int j;

	if (*to_find == '\0')
		return ((char *)str);
	i = 0;
	while (i < (int)len && str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j] && j + i < (int)len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (0);
}
