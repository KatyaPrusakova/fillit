/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:24:58 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 18:15:42 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’,
** result of the concatenation of s1 and s2. If the allocation fails the
** function returns NULL.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		len = ft_strlen(s2);
	else if (s2 == NULL)
		len = ft_strlen(s1);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	if (!(newstr = ft_strnew(len + 1)))
		return (NULL);
	if (s1 == NULL)
		ft_strcpy(newstr, s2);
	else if (s2 == NULL)
		ft_strcpy(newstr, s1);
	else
	{
		ft_strcpy(newstr, s1);
		ft_strcat(newstr, s2);
	}
	return (newstr);
}
