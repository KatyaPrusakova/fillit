/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:18:56 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 14:08:29 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copy the string src to dst (including the terminating `\0' character.)
**
** Return dst.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
