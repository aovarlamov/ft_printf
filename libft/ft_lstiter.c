/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:12:03 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/17 17:59:35 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*lst_ptr;

	lst_ptr = lst;
	while (lst_ptr)
	{
		(*f)(lst_ptr);
		lst_ptr = lst_ptr->next;
	}
}
