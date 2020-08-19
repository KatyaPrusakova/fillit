/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:30:17 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/05 13:35:52 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the integer n to the file descriptor fd.
*/

void	ft_putnbr_fd(int n, int fd)
{
	long nbr;

	if (fd != -1)
	{
		nbr = n;
		if (nbr < 0)
		{
			ft_putchar_fd('-', fd);
			nbr *= -1;
		}
		if (nbr > 9)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putchar_fd(nbr % 10 + '0', fd);
		}
		else
		{
			ft_putchar_fd(nbr + '0', fd);
		}
	}
}
