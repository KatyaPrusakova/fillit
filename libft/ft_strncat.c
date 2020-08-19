/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:48:08 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 14:19:34 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Append a copy of the null-terminated string s2 to the end of the
** null-terminated string s1, then add a terminating `\0'. The string s1 must
** have sufficient space to hold the result. Appends not more than n characters
** from s2, and then adds a terminating `\0'.
**
** Return the pointer s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (j < n && s2[j] != '\0')
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
