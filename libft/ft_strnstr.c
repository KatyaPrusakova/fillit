/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:21:27 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 18:16:03 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of the null-terminated string needle in the
** string haystack, where not more than len characters are searched. Characters
** that appear after a `\0' character are not searched.
**
** If needle is an empty string, haystack is returned; if needle occurs nowhere
** in haystack, NULL is returned; otherwise a pointer to the first character of
** the first occurrence of needle is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_size;
	size_t	haystack_size;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	needle_size = ft_strlen(needle);
	haystack_size = (haystack != NULL) ? ft_strlen(haystack) : 1;
	while (i + needle_size < len + 1 && i + needle_size <= haystack_size &&
		haystack[i] != '\0')
	{
		if (ft_strncmp(&haystack[i], needle, needle_size) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
