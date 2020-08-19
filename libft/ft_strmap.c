/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:55:32 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 18:15:39 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the string given
** as argument to create a “fresh” new string (with malloc(3))
** resulting from the successive applications of f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	if (s == NULL || f == NULL || !(newstr = ft_strnew(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = f(s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
