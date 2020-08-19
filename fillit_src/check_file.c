/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:51:42 by jpalgi            #+#    #+#             */
/*   Updated: 2020/07/13 15:41:09 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check if line has only allowed characters ('#' and '.') and if line is 4
** characters long. If OK returns 1, otherwise 0.
*/

static int		check_line_is_valid(char *line)
{
	int len;

	len = 0;
	while (line[len] != '\0')
	{
		if (line[len] != '#' && line[len] != '.')
			return (0);
		len++;
	}
	if (len == 4)
		return (1);
	return (0);
}

/*
** Malloc memory for tetrimino 4x4 char grid to hold the read tetrimino and
** return it.
*/

static char		**init_tetrimino(void)
{
	int		i;
	char	**tetrimino;

	i = 0;
	if (!(tetrimino = (char **)malloc(sizeof(char *) * (4 + 1))))
		return (NULL);
	while (i < 4)
	{
		if (!(tetrimino[i] = ft_strnew(4 + 1)))
		{
			tetrimino[i] = 0;
			free_tetrimino(tetrimino);
			return (NULL);
		}
		i++;
	}
	tetrimino[i] = 0;
	return (tetrimino);
}

/*
** Return logic computation: if line exists AND (line not empty AND line has 4
** chars and only allowed chars OR number of rows read is 1 and line is empty
** OR number rows read is 5 and line is not empty). If previous is true (1) then
** also line is cleared if ret == 0, else the line would not be freed.
** Was made to save space in check_file_is_valid. :D
*/

static int		check_line_length(char *line, int num_rows, int ret)
{
	int line_has_required_length;

	line_has_required_length = (line &&
					((!ft_strequ(line, "") && !check_line_is_valid(line)) ||
					(num_rows == 1 && ft_strequ(line, "")) ||
					(num_rows == 5 && !ft_strequ(line, ""))));
	if (line_has_required_length)
	{
		if (ret != 0)
			ft_strdel(&line);
	}
	return (line_has_required_length);
}

/*
** If number of rows read is 5 and read line is empty then number of rows = 0,
** because next (assumable) its going to be a new tetrimino.
** Was made to save space in check_file_is_valid. :D
*/

static void		check_num_rows(int *num_rows, char *line)
{
	if (*num_rows == 5 && ft_strequ(line, ""))
		*num_rows = 0;
}

/*
** Checks if file contains valid tetriminos and the file has correct structure.
** If all good then the line is copied to malloced 4x4 tetrimino grid. If
** tetrimino is fully read then it will be added as an element to linked list.
** Returns -1 in case of and error, otherwise 1.
*/

int				check_file_is_valid(int fd, t_tetriminos **lst)
{
	char	*line;
	int		num_rows;
	char	**tetrimino;
	int		ret;
	int		check;

	num_rows = 0;
	check = 0;
	while ((ret = get_next_line(fd, &line)) != -1 && ++num_rows)
	{
		if (num_rows == 1)
			if (!(tetrimino = init_tetrimino()))
				return (free_all_tetriminos(lst));
		if (check_line_length(line, num_rows, ret))
			return (free_all(tetrimino, lst));
		check_num_rows(&num_rows, line);
		if (line && line[0] != '\0' && ret != 0)
			ft_strcpy(tetrimino[num_rows - 1], line);
		else if (((!num_rows || (num_rows == 5 && !line)) &&
				(check = check_tetris(tetrimino, lst))) || !ret)
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (return_check(check, (ret == -1 || num_rows != 5), lst, tetrimino));
}
