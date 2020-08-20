/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:06:03 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/17 18:03:04 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *temp;

	if (!(*alst))
		*alst = new;
	else
	{
		temp = new;
		temp->next = *alst;
		*alst = temp;
	}
}
