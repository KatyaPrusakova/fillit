/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:53:22 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 14:06:58 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates sufficient memory for a copy of the string s1, does the copy,
** and returns a pointer to it.
**
** If insufficient memory is available, NULL is returned.
*/

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	if (!(dst = (char *)ft_memalloc(ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
