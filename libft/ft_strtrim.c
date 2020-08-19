/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:07:46 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/11 19:29:38 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a copy of the string given
** as argument without whitespaces at the beginning or at the end of the string.
** Will be considered as whitespaces the following characters ’ ’, ’\n’ and
** ’\t’. If s has no whitespaces at the beginning or at the end, the function
** returns a copy of s. If the allocation fails the function returns NULL.
*/

char		*ft_strtrim(char const *s)
{
	int	len;
	int	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!ft_iswhitespace(s[0]) && !ft_iswhitespace(s[len - 1]))
		return (ft_strdup(s));
	i = 0;
	while (ft_iswhitespace(s[i]) && i < len)
		i++;
	while (ft_iswhitespace(s[len - 1]) && len > i)
		len--;
	if (len - i == 0)
		return (ft_strsub(s, 0, 0));
	return (ft_strsub(s, i, len - i));
}
