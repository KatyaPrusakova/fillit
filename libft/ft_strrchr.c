/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:38:46 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 15:10:33 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Locates the last occurrence of c (converted to a char) in the string
** pointed to by s.  The terminating null character is considered to be part of
** the string; therefore if c is `\0', the functions locate the terminating `\0'
**
** Return a pointer to the located character, or NULL if the character does not
** appear in the string.
*/

char	*ft_strrchr(const char *s, int c)
{
	char *last_occurrence_of_c;

	last_occurrence_of_c = NULL;
	while (*s != '\0')
	{
		if (*s == c)
		{
			last_occurrence_of_c = (char *)s;
		}
		s++;
	}
	if (c == '\0')
		last_occurrence_of_c = (char *)s;
	return (last_occurrence_of_c);
}
