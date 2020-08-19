/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:58:04 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 16:58:35 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Outputs the character c to the standard output.
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
