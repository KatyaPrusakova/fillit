/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 15:16:57 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 18:15:38 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the string passed as argument
** by giving its index as first argument to create a “fresh” new string
** (with malloc(3)) resulting from the successive applications of f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	if (s == NULL || f == NULL || !(newstr = ft_strnew(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
