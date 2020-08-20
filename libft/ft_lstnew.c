/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:29:14 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/17 18:03:14 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	if ((temp = (t_list *)malloc(sizeof(t_list))))
	{
		if (content == 0 || content_size == 0)
		{
			temp->content = 0;
			temp->content_size = 0;
		}
		else
		{
			if (!(temp->content = (void *)malloc(sizeof(content)
			* content_size)))
				return (0);
			temp->content = ft_memcpy(temp->content, content, content_size);
			temp->content_size = content_size;
		}
		temp->next = 0;
		return (temp);
	}
	return (0);
}
