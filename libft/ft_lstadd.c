/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:50:24 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 17:09:26 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the element new at the beginning of the list.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new && alst)
	{
		new->next = *alst;
		*alst = new;
	}
}
