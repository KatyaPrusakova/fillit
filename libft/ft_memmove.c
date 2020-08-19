/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 13:47:58 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/12 10:45:11 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Copies len bytes from string src to string dst. The two strings may overlap;
** the copy is always done in a non-destructive manner.
**
** Returns the value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	temp[len];
	size_t	i;

	i = 0;
	while (i < len)
	{
		temp[i] = *((char *)src);
		i++;
		src++;
	}
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = temp[i];
		i++;
	}
	return (dst);
}
