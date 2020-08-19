/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:53:53 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 18:13:59 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the integer n given as argument. Negative numbers must be
** supported. If the allocation fails, the function returns NULL.
*/

static int		intlen(long nbr)
{
	int digits;

	digits = 0;
	while (nbr != 0 || digits == 0)
	{
		digits++;
		nbr /= 10;
	}
	return (digits);
}

char			*ft_itoa(int n)
{
	long	nbr;
	int		neg;
	int		nbrlen;
	char	*str;

	nbr = (n < 0) ? (long)n * -1 : (long)n;
	neg = (n < 0) ? 1 : 0;
	nbrlen = intlen(nbr);
	if (!(str = ft_strnew(nbrlen + neg + 1)))
		return (NULL);
	str[neg + nbrlen] = '\0';
	nbrlen--;
	while (nbrlen + neg >= 0)
	{
		str[neg + nbrlen] = (nbr % 10) + '0';
		nbrlen--;
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
