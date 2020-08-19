/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:30:15 by jpalgi            #+#    #+#             */
/*   Updated: 2020/07/19 21:20:28 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Free 4x4 char grid.
*/

int		free_tetrimino(char **tetrimino)
{
	int	i;

	i = 0;
	while (tetrimino[i] != 0)
	{
		free(tetrimino[i]);
		tetrimino[i] = NULL;
		i++;
	}
	free(tetrimino);
	tetrimino = NULL;
	return (-1);
}

/*
** Free the linked list.
*/

int		free_all_tetriminos(t_tetriminos **tetriminos)
{
	t_tetriminos	*temp;

	while (*tetriminos)
	{
		temp = (*tetriminos);
		*tetriminos = (*tetriminos)->next;
		free_tetrimino(temp->tetrimino);
		free(temp->start);
		free(temp);
		temp = NULL;
	}
	return (-1);
}

/*
** Free existing 4x4 char grid and the linked list.
*/

int		free_all(char **tetrimino, t_tetriminos **tetriminos)
{
	if (tetrimino)
		free_tetrimino(tetrimino);
	if (tetriminos && *tetriminos)
		free_all_tetriminos(tetriminos);
	return (-1);
}

/*
** Free 2 int arrs and pos if it exists and return given return value.
*/

int		free_int_arr(int *arr1, int *arr2, int **pos, int return_val)
{
	int i;

	free(arr1);
	free(arr2);
	if (pos)
	{
		i = 0;
		while (i < 4)
		{
			free(pos[i]);
			i++;
		}
		free(pos);
	}
	return (return_val);
}
