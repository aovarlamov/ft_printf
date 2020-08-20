/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:23:14 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/17 19:24:06 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	if (ft_isprint(s[i]) == 1 && s[i] != c)
		words++;
	while (s[i] != '\0')
	{
		if (ft_isprint(s[i]) == 1 && s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}
