/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:11:36 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/17 19:25:08 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsplit_words(char const *s, char c)
{
	int		i;
	int		words;

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

static int	ft_strsplit_lenword(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

static void	ft_strsplit_free(char **res, int w)
{
	while (w >= 0)
		ft_strdel(&res[w--]);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		words;
	int		w;
	int		lw;

	if (!s || !c)
		return (0);
	words = ft_strsplit_words(s, c);
	if (!(res = (char **)malloc(sizeof(res) * words + 1)))
		return (0);
	res[words] = 0;
	w = 0;
	while (w < words)
	{
		while (*s == c)
			s++;
		lw = ft_strsplit_lenword(s, c);
		if (!(res[w] = ft_strsub(s, 0, lw)))
			ft_strsplit_free(res, w);
		s += lw;
		w++;
	}
	return (res);
}
