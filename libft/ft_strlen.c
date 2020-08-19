/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 13:00:07 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/09 17:36:46 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Computes the length of the string s.
**
** Returns the number of characters that precede the terminating NUL character.
*/

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s && s[len] != '\0')
	{
		len++;
	}
	return (len);
}
