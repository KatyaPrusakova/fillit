/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_toend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:22:44 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/12 11:37:02 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add new element to the end of the list pointed. If *head is NULL *new will
** be the new head. If head is NULL then the fun can't add to the end of NULL.
**
** Returns the last element of the list (which is *new).
*/

t_list		*ft_lstadd_toend(t_list **head, t_list *new)
{
	t_list	*list;

	if (!head)
		return (NULL);
	list = *head;
	if (!list)
	{
		*head = new;
		return (*head);
	}
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
		return (new);
	}
}
