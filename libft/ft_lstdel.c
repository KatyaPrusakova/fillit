/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:25:01 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 18:14:11 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes as a parameter the adress of a pointer to a link and frees the memory
** of this link and every successors of that link using the functions del and
** free(3). Finally the pointer to the link that was just freed must be set to
** NULL (quite similar to the function ft_memdel from the mandatory part).
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	while (alst && del && *alst)
	{
		temp = *alst;
		*alst = (*alst)->next;
		if (temp->content)
			del(temp->content, temp->content_size);
		ft_memdel((void **)&temp);
	}
}
