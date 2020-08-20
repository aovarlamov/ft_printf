/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:23:38 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/17 19:20:16 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst_ptr;
	t_list	*lst_ptr2;

	if (!lst || !f)
		return (0);
	if (!(lst_ptr = f(lst)))
	{
		free(lst_ptr);
		return (0);
	}
	lst_ptr2 = lst_ptr;
	while (lst->next)
	{
		lst = lst->next;
		if (!(lst_ptr->next = f(lst)))
		{
			free(lst_ptr->next);
			return (0);
		}
		lst_ptr = lst_ptr->next;
	}
	return (lst_ptr2);
}
