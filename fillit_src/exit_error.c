/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 21:09:16 by jpalgi            #+#    #+#             */
/*   Updated: 2020/07/19 21:19:39 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** If some allocation fails during the solving part of program then "error" is
** printed and list and grid freed and program exited.
*/

void	exit_error(char **grid, t_tetriminos **lst)
{
	ft_putendl("error");
	exit(free_all(grid, lst));
}
