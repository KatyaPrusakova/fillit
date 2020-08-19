/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:03:27 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/12 10:04:21 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Free every element of the list.
*/

void	ft_lstfree(t_list **list)
{
	t_list *temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->content);
		ft_memdel((void **)&temp);
	}
}
