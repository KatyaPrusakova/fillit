/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:23:15 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 13:56:32 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Locates the first occurrence of c (converted to an unsigned char)
** in string s.
**
** Returns a pointer to the byte located, or NULL if no such byte exists
** within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return (&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
