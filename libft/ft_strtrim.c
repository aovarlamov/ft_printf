/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:47:52 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/16 18:15:25 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (0);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == '\n' || s[start] == '\t' || s[start] == ' ')
		start++;
	while (s[end] == '\n' || s[end] == '\t' || s[end] == ' ')
		end--;
	if (end == -1)
		end = start - 1;
	if (!(res = (char *)malloc(sizeof(*res) * end - start + 2)))
		return (0);
	i = 0;
	while (start <= end)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
