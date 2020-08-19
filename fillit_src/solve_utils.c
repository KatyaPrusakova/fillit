/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:17:35 by jpalgi            #+#    #+#             */
/*   Updated: 2020/07/19 21:21:47 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Initializes a grid of size x size and sets each char to '.'.
*/

char	**init_grid(int size)
{
	char	**grid;
	int		i;
	int		j;

	i = 0;
	if (!(grid = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * (size + 1))))
		{
			grid[i] = 0;
			free_tetrimino(grid);
			return (NULL);
		}
		j = 0;
		while (j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i++][j] = '\0';
	}
	grid[i] = 0;
	return (grid);
}

/*
** Inserts given char c to 4 given positions.
** Returns 1 to save line count in insert().
*/

int		insert_tetrimino(char **grid, int **pos, char c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		grid[pos[i][0]][pos[i][1]] = c;
		free(pos[i]);
		i++;
	}
	free(pos);
	return (1);
}

/*
** Calculates and returns the inital size of the grid using the list size.
*/

int		get_grid_size(int lst_size)
{
	int sqrt_size;
	int initial_size;

	initial_size = lst_size * 4;
	while ((sqrt_size = ft_sqrt(initial_size)) == 0)
	{
		initial_size++;
	}
	return (sqrt_size);
}

/*
** Insert was made and this function is to call the recursive() fun again to
** solve the puzzle. If some next tetrimino doesnt fit then its backtracked and
** removed.
*/

int		insert_ok(t_tetriminos **lst, char **grid, char c)
{
	int i;
	int j;

	if ((*lst)->next)
	{
		if (recursive(&(*lst)->next, grid, c + 1))
			return (1);
		i = -1;
		while (grid[++i] != 0)
		{
			j = 0;
			while (grid[i][j] != '\0')
			{
				if (grid[i][j] == c)
					grid[i][j] = '.';
				j++;
			}
		}
		return (0);
	}
	return (1);
}

/*
** Allocates memory for pos[4][2] to save the positions of the next '#'s. If
** allocation fails then its needed to free existing pos and list and existing
** grid and exit the program.
*/

int		**allocate_pos(t_tetriminos **lst, char **grid)
{
	int i;
	int j;
	int **pos;

	if (!(pos = (int **)malloc(sizeof(int *) * 4)))
		exit_error(grid, lst);
	i = 0;
	j = -1;
	while (i < 4)
	{
		if (!(pos[i] = (int *)malloc(sizeof(int) * 2)))
			j = 0;
		i++;
	}
	if (j == -1)
		return (pos);
	j = 0;
	while (j < i)
	{
		free(pos[j]);
		j++;
	}
	free(pos);
	exit_error(grid, lst);
	return (NULL);
}
