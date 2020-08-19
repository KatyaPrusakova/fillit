/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:35:34 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 16:35:55 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sets every character of the string to the value ’\0’.
*/

void	ft_strclr(char *s)
{
	if (s)
	{
		ft_bzero((void *)s, ft_strlen(s));
	}
}
