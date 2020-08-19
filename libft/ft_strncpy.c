/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:18:56 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/16 18:51:48 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Copy at most len characters from src into dst. If src is less than len
** characters long, the remainder of dst is filled with `\0' characters.
** Otherwise, dst is not terminated.
**
** Return dst.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && *src != '\0')
	{
		dst[i] = *src;
		i++;
		src++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
