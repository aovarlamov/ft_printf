/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:42:11 by kbethel           #+#    #+#             */
/*   Updated: 2019/12/08 22:31:06 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*temp2;

	temp = *alst;
	while (temp)
	{
		temp2 = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = temp2;
	}
	*alst = NULL;
}
