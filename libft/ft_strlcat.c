/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 10:51:49 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 18:15:41 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends string src to the end of dst. It will append at most
** dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
** dstsize is 0 or the original dst string was longer than dstsize (in practice
** this should not happen as it means that either dstsize is incorrect or that
** dst is not a proper string).
**
** Return the total length of the string function tried to create:
** initial length of dst plus the length of src.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	j;
	size_t	initial_dest_size;

	initial_dest_size = (dst != NULL) ? ft_strlen(dst) : 0;
	j = initial_dest_size;
	i = 0;
	while (dstsize > j + 1 && src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (i != 0 || (j == initial_dest_size && dstsize > initial_dest_size))
	{
		dst[j] = '\0';
		return (ft_strlen(src) + initial_dest_size);
	}
	return (ft_strlen(src) + dstsize);
}
