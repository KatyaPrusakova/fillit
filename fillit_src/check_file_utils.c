/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:39:13 by jpalgi            #+#    #+#             */
/*   Updated: 2020/07/18 21:57:44 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check is 0 if tetrimino was valid and was added to list, otherwise its -1.
** free is get_next_line() == -1 || number of read rows != 5, means that we have
** not read a full tetrimino.
** Was made to save 1 line in check_file_is_valid. :D
*/

int	return_check(int check, int free, t_tetriminos **lst, char **tetrimino)
{
	return ((check || ((free || !*lst) && free_all(tetrimino, lst))) ? -1 : 1);
}
