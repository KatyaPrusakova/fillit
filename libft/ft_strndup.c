/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:10:35 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/30 16:25:08 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates len amount of memory for a copy of the string starting from the
** pointed position of s1, does the copy and returns a pointer to it.
**
** If insufficient memory is available, NULL is returned.
*/

char	*ft_strndup(const char *s1, size_t len)
{
	char	*dst;
	size_t	i;

	if (!(dst = ft_strnew(len + 1)))
		return (NULL);
	i = 0;
	while (i < len && *s1 != '\0')
	{
		dst[i] = *s1;
		i++;
		s1++;
	}
	dst[i] = '\0';
	return (dst);
}
