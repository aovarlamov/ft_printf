/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:30:08 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/09 18:34:33 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *res;

	res = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (res);
}
