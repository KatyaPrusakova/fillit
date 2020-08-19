/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 17:32:38 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/12 14:29:22 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If newlen is bigger than originallen ft_realloc creates a new allocation,
** copies old data pointed to by ptr to the new allocation, frees the old
** allocation, and returns a pointer to the allocated memory. New allocated
** memory is initialized to 0. If originallen is equal or bigger than newlen,
** the given ptr is returned. If ptr is NULL, ft_realloc() is identical to a
** call to malloc() for newlen bytes. If newlen is zero, ptr is freed and NULL
** returned.
**
** Return a pointer to allocated memory or NULL on error.
*/

void	*ft_realloc(void *ptr, size_t originallen, size_t newlen)
{
	void *ptrnew;

	if (newlen == 0)
	{
		ft_memdel(&ptr);
		return (NULL);
	}
	else if (!ptr)
		return (ptrnew = ft_memalloc(newlen));
	else if (newlen <= originallen)
		return (ptr);
	else
	{
		if (!(ptrnew = ft_memalloc(newlen)))
		{
			ft_memdel(&ptr);
			return (NULL);
		}
		ft_memcpy(ptrnew, ptr, originallen);
		ft_memdel(&ptr);
		return (ptrnew);
	}
}
