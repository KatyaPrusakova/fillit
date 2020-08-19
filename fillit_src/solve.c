/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:35:11 by jpalgi            #+#    #+#             */
/*   Updated: 2020/07/19 21:16:25 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	g_c_for_grid = 'A';
int		g_size;

/*
** Allocate and return an int array[2] with the given i and j.
*/

static int	*get_row_col(int i, int j)
{
	int *row_col;

	if (!(row_col = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	row_col[0] = i;
	row_col[1] = j;
	return (row_col);
}

/*
** Returns true if grid size allows insertion to i and j AND the grid[i][j] is
** and empty place '.'. i_j[1] - 1, because +1 j is given.
** Made to save space in the insert().
*/

static int	check_for_valid_insert(int *start, char **grid, int *row_col,
																	int *i_j)
{
	return ((row_col[0] + (i_j[0] - start[0])) < g_size &&
			(row_col[1] + (i_j[1] - 1 - start[1]) < g_size) &&
			(grid[row_col[0] + (i_j[0] - start[0])]
								[row_col[1] + (i_j[1] - 1 - start[1])] == '.'));
}

/*
** Checks if its valid to insert char (as '#') to current grid and if 4 valid
** insertions are saved then calls insert_tetrimino() to insert it.
** Returns 1 if tetrimino was inserted, otherwise 0.
*/

static int	insert(t_tetriminos **lst, char **grid, int *row_col, int **pos)
{
	int *i_j;
	int	count;

	count = 0;
	if (!(i_j = get_row_col(0, 0)))
		exit_error(grid, lst);
	i_j[0] = (*lst)->start[0];
	while ((*lst)->tetrimino[i_j[0]] != 0)
	{
		i_j[1] = (i_j[0] == (*lst)->start[0]) ? (*lst)->start[1] : 0;
		while ((*lst)->tetrimino[i_j[0]][i_j[1]] != '\0')
		{
			if ((*lst)->tetrimino[i_j[0]][i_j[1]++] == '#')
			{
				if (!check_for_valid_insert((*lst)->start, grid, row_col, i_j))
					return (free_int_arr(row_col, i_j, pos, 0));
				pos[count][0] = row_col[0] + (i_j[0] - (*lst)->start[0]);
				pos[count++][1] = row_col[1] + (i_j[1] - 1 - (*lst)->start[1]);
			}
			if (count == 4 && free_int_arr(row_col, i_j, NULL, 1))
				return (insert_tetrimino(grid, pos, g_c_for_grid));
		}
		i_j[0]++;
	}
	return (free_int_arr(row_col, i_j, pos, 0));
}

/*
** Heart of the puzzel as solving with the recursive power. Starts to iterate
** the grid and looks for an empty place '.'. If empty palce found try to insert
** current char c into grid. If insert was successful then it means all the
** recursive functions calls were successful, return 1! If insert_ok() returns 0
** then it means we need to move the current tetrimino to next possible position
** and try again. If every possible position is tried and still inserting and
** some point fails then return 0.
*/

int			recursive(t_tetriminos **lst, char **grid, char c)
{
	int *row_col;
	int	i;
	int	j;

	i = -1;
	while (grid[++i] != 0)
	{
		j = 0;
		while (grid[i][j] != '\0')
		{
			if (grid[i][j++] == '.')
			{
				if (!(row_col = get_row_col(i, j - 1)))
					exit_error(grid, lst);
				g_c_for_grid = c;
				if (insert(lst, grid, row_col, allocate_pos(lst, grid)))
				{
					if (insert_ok(lst, grid, c))
						return (1);
				}
			}
		}
	}
	return (0);
}

/*
** Gets the inital size of the grid. Starts the puzzle solving and the ends the
** solving by printing the grid out. Everytime the insertion has failed the
** grid is freed and a new one sizes bigger grid is made to solve the puzzle.
*/

int			solve_puzzle(t_tetriminos **tetriminos, int lst_size)
{
	int		i;
	char	**grid;

	g_size = get_grid_size(lst_size);
	while ((grid = init_grid(g_size)))
	{
		if (recursive(tetriminos, grid, 'A') == 1)
		{
			i = 0;
			while (grid[i] != 0)
			{
				ft_putendl(grid[i]);
				i++;
			}
			free_tetrimino(grid);
			return (1);
		}
		free_tetrimino(grid);
		g_size++;
	}
	return (-1);
}
