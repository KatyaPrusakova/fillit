/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:01:56 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 18:16:22 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” substring from the string
** given as argument. The substring begins at index start and is of size len.
** If start and len aren’t refering to a valid substring, the behavior
** is undefined. If the allocation fails, the function returns NULL.
** If given start and len won't be matching a SUB string then return NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s == NULL || ft_strlen(s) < start + len ||
			!(substr = ft_strnew(len + 1)))
		return (NULL);
	ft_strncpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
