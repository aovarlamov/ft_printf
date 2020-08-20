/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:38:18 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/16 23:28:37 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*res;
	unsigned char	*cpy;

	if (!dest && !src)
		return (0);
	cpy = (unsigned char *)src;
	res = (unsigned char *)dest;
	i = 0;
	while (i < (int)n)
	{
		res[i] = cpy[i];
		i++;
	}
	return (dest);
}
