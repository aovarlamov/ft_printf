/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:06:13 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/16 22:49:56 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	int		i;
	int		j;

	i = 0;
	while (dest[i] != '\0' && i < (int)len)
		i++;
	j = 0;
	while (src[j] != '\0' && i < (int)len - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i - j < (int)len)
		dest[i] = '\0';
	return (i - j + ft_strlen(src));
}
