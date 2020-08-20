/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:23:20 by kbethel           #+#    #+#             */
/*   Updated: 2019/11/03 22:49:36 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (0);
	if (!(res = (char *)malloc(sizeof(*res) * len + 1)))
		return (0);
	i = 0;
	while (s[start] != '\0' && i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
