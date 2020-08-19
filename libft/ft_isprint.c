/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:35:44 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/04 10:12:43 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (ASCII_PRINT_FIRST <= c && c <= ASCII_PRINT_LAST)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}