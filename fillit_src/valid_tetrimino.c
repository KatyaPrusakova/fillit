/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:05:37 by jpalgi            #+#    #+#             */
/*   Updated: 2020/07/19 21:23:18 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Validates tetriminos '#' positions and its count. They should be next to each
** other not far apart.
** no upper && before && upper right && next -> ++, ++ if one before the before
** Next -> call again with count as 1
** Down and previous && no previous && down -> call again with count as 1
** Down -> call again with count as 1
*/

static int	validate_tetrimino(char **tetrimino, int i, int j, int count)
{
	if (j != 0 && i != 0 && j < 3 && tetrimino[i - 1][j] != '#' &&
		tetrimino[i][j - 1] == '#' && tetrimino[i - 1][j + 1] == '#' &&
		tetrimino[i][j + 1] == '#')
	{
		count++;
		if (j > 1 && tetrimino[i][j - 2] == '#')
			count++;
	}
	if (j < 3 && tetrimino[i][j + 1] == '#')
		count += validate_tetrimino(tetrimino, i, j + 1, 1);
	if (i < 3 && j != 0 && tetrimino[i + 1][j - 1] == '#' &&
		tetrimino[i][j - 1] != '#' && tetrimino[i + 1][j] == '#')
		count += validate_tetrimino(tetrimino, i + 1, j - 1, 1);
	else if (i < 3 && tetrimino[i + 1][j] == '#')
		count += (i < 3 && tetrimino[i + 1][j + 1] == '#'
						&& tetrimino[i][j + 1] == '#')
				? validate_tetrimino(tetrimino, i + 1, j, 0)
				: validate_tetrimino(tetrimino, i + 1, j, 1);
	return (count);
}

/*
** Sets the linked list elements *start (which is allocated here, start[2]) with
** the first occurence of the '#' i and j respectively. Fun will never make it
** to the last return in fun.
*/

static int	init_tetrimino_start(t_tetriminos **tetrimino)
{
	int i;
	int j;

	i = 0;
	while ((*tetrimino)->tetrimino[i] != 0)
	{
		j = 0;
		while ((*tetrimino)->tetrimino[i][j] != '\0')
		{
			if ((*tetrimino)->tetrimino[i][j] == '#')
			{
				if (!((*tetrimino)->start = (int *)malloc(sizeof(int) * 2)))
					return (-1);
				(*tetrimino)->start[0] = i;
				(*tetrimino)->start[1] = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

/*
** Create a new element in the end of the linked list. Assing elements tetrimino
** and its *start.
*/

static int	add_to_tetriminos(char **tetrimino, t_tetriminos **tetriminos)
{
	t_tetriminos *temp;

	temp = *tetriminos;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		if (!(temp->next = (t_tetriminos *)ft_memalloc(sizeof(t_tetriminos))))
			return (free_all(tetrimino, tetriminos));
		temp = temp->next;
	}
	else
	{
		if (!(temp = (t_tetriminos *)ft_memalloc(sizeof(t_tetriminos))))
			return (-1);
		*tetriminos = temp;
	}
	temp->tetrimino = tetrimino;
	temp->next = NULL;
	return (init_tetrimino_start(&temp));
}

/*
** Validates tetrimino as a valid tetrimino where it consists of 4 '#'.
*/

static int	count_hashtag(char **tetrimino)
{
	int i;
	int j;
	int hashtag_count;

	i = 0;
	hashtag_count = 0;
	while (tetrimino[i] != 0)
	{
		j = 0;
		while (tetrimino[i][j] != '\0')
		{
			if (tetrimino[i][j] == '#')
				hashtag_count++;
			j++;
		}
		i++;
	}
	return (hashtag_count == 4) ? 1 : 0;
}

/*
** Validates tetrimino as a valid tetrimino where it takes into account that
** each tetrmino consists of 4 '#' and each of them must be connected by 2 of
** other '#'. If tetrimino valid then add it to list as element, otherwise free
** and return -1 for error.
*/

int			check_tetris(char **tetrimino, t_tetriminos **tetriminos)
{
	int	i;
	int	j;

	i = 0;
	while (tetrimino[i] != 0)
	{
		j = 0;
		while (tetrimino[i][j] != '\0')
		{
			if (tetrimino[i][j] == '#')
			{
				if (count_hashtag(tetrimino) &&
					validate_tetrimino(tetrimino, i, j, 1) == 4)
					return (add_to_tetriminos(tetrimino, tetriminos));
				else
					return (free_all(tetrimino, tetriminos));
			}
			j++;
		}
		i++;
	}
	return (free_all(tetrimino, tetriminos));
}
