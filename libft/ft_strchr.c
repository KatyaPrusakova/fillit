/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:38:46 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/16 18:55:08 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Locates the first occurrence of c (converted to a char) in the string
** pointed to by s.  The terminating null character is considered to be part of
** the string; therefore if c is `\0', the functions locate the terminating `\0'
**
** Return a pointer to the located character, or NULL if the character does not
** appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
