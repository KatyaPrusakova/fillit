/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:24:36 by jpalgi            #+#    #+#             */
/*   Updated: 2020/07/19 21:24:36 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Calculates and returns how many elements (tetrimino) are in the linked list
** (tetriminos).
*/

static int	tetriminos_length(t_tetriminos **tetriminos)
{
	int				i;
	t_tetriminos	*temp;

	temp = *tetriminos;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

/*
** Checks parameters count and on any error prints "error\n". Also file opening
** is checked and if given file has valid tetriminos and valid file structure
** and if more than 26 tetriminos are in the file.
** If all previous was OK then will solve the puzzle.
*/

int			main(int argc, char const *argv[])
{
	int				fd;
	t_tetriminos	*tetriminos;
	int				lst_size;

	tetriminos = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" source_file");
	}
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1 ||
			check_file_is_valid(fd, &tetriminos) == -1 ||
			(lst_size = tetriminos_length(&tetriminos)) > 26)
			ft_putendl("error");
		else
			solve_puzzle(&tetriminos, lst_size);
		close(fd);
	}
	free_all_tetriminos(&tetriminos);
	return (0);
}
