/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:22:52 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/05 13:29:43 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string s to the file descriptor fd
*/

void	ft_putstr_fd(char const *s, int fd)
{
	if (s && fd != -1)
	{
		while (*s != '\0')
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}
