/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 11:06:06 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/12 10:05:11 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Iterates a list lst and applies the function f to each link to create a
** “fresh” list (using malloc(3)) resulting from the successive applications
** of f. If the allocation fails, the function returns NULL.
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first_link;
	t_list	*link;
	t_list	*mappd;

	if (lst == NULL || f == NULL)
		return (NULL);
	mappd = f(lst);
	if (!(first_link = ft_lstnew(mappd->content, mappd->content_size)))
		return (NULL);
	link = first_link;
	while (lst->next)
	{
		mappd = f(lst->next);
		if (!(link->next = ft_lstnew(mappd->content, mappd->content_size)))
		{
			ft_lstfree(&first_link);
			return (NULL);
		}
		link = link->next;
		lst = lst->next;
	}
	return (first_link);
}
