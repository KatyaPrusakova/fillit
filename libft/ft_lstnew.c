/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 16:04:44 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/12 14:03:43 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” link. The variables content
** and content_size of the new link are initialized by copy of the parameters
** of the function. If the parameter content is nul, the variable content is
** initialized to NULL and the variable content_size is initialized to 0 even
** if the parameter content_size isn’t. The variable next is initialized
** to NULL. If the allocation fails, the function returns NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlink;

	if (!(newlink = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(newlink->content = (void *)ft_memalloc(content_size)))
	{
		ft_memdel((void **)&newlink);
		return (NULL);
	}
	if (content == NULL)
	{
		newlink->content = NULL;
		newlink->content_size = 0;
	}
	else
	{
		ft_memmove(newlink->content, content, content_size);
		newlink->content_size = content_size;
	}
	newlink->next = NULL;
	return (newlink);
}
