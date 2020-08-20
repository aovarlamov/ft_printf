/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:15:53 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/16 23:44:29 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*res;
	unsigned char	*cpy;

	cpy = (unsigned char *)src;
	res = (unsigned char *)dest;
	i = 0;
	while (i < (int)n)
	{
		res[i] = cpy[i];
		if (cpy[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
