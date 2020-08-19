/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 16:45:38 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 18:15:36 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographical comparison between s1 and s2 up to n characters or until
** a ’\0’ is reached. If the 2 strings are identical, the function
** returns 1, or 0 otherwise.
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	else
		return (0);
}
