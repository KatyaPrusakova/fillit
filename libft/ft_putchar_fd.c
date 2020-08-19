/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:13:23 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 17:01:48 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Outputs the char c to the file descriptor fd.
*/

void	ft_putchar_fd(char c, int fd)
{
	if (fd != -1)
	{
		write(fd, &c, 1);
	}
}
