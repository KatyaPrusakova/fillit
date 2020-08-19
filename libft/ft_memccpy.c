/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 13:36:29 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 13:50:58 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Copies bytes from string src to string dst. If the character c (as converted
** to an unsigned char) occurs in the string src, the copy stops and a pointer
** to the byte after the copy of c in the string dst is returned. Otherwise,
** n bytes are copied, and a NULL pointer is returned. The source and
** destination strings should not overlap, as the behavior is undefined.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
