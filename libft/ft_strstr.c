/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:58:44 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 18:16:18 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of the null-terminated string needle in the
** null-terminated string haystack.
**
** If needle is an empty string, haystack is returned; if needle occurs nowhere
** in haystack, NULL is returned; otherwise a pointer to the first character of
** the first occurrence of needle is returned.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	needle_size;
	size_t	haystack_size;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	haystack_size = ft_strlen(haystack);
	needle_size = ft_strlen(needle);
	while (haystack[i] != '\0' && i + needle_size <= haystack_size)
	{
		if (ft_strncmp(&haystack[i], needle, needle_size) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
