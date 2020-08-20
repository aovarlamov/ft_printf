/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:04:26 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/17 03:02:08 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*res;
	unsigned char	*cpy;

	i = 0;
	if (!dest && !src)
		return (dest);
	cpy = (unsigned char *)src;
	res = (unsigned char *)dest;
	if (dest > src)
	{
		while ((int)--n >= 0)
			res[n] = cpy[n];
	}
	else
	{
		while (i < (int)n)
		{
			res[i] = cpy[i];
			i++;
		}
	}
	return (dest);
}
