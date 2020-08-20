/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:16:00 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/17 18:08:38 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	uch;

	uch = (unsigned char)ch;
	res = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (res[i] == uch)
			return (res + i);
		i++;
	}
	return (0);
}
