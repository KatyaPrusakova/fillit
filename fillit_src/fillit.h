/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:23:06 by jpalgi            #+#    #+#             */
/*   Updated: 2020/07/19 21:12:24 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

/*
** *start is a int arr[2], where arr[0] is i of the first '#' and arr[1] the j.
** **tetrimino is the 4x4 grid which was read from the file.
*/

typedef struct	s_tetriminos
{
	int					*start;
	char				**tetrimino;
	struct s_tetriminos	*next;
}				t_tetriminos;

int				free_tetrimino(char **arr);
int				free_all_tetriminos(t_tetriminos **tetriminos);
int				free_all(char **tetrimino, t_tetriminos **tetriminos);
int				free_int_arr(int *arr1, int *arr2, int **pos, int return_val);
int				check_file_is_valid(int fd, t_tetriminos **lst);
int				check_tetris(char **tetrimino, t_tetriminos **tetriminos);
int				solve_puzzle(t_tetriminos **tetriminos, int lst_size);
char			**init_grid(int size);
int				insert_tetrimino(char **grid, int **pos, char c);
int				get_grid_size(int lst_size);
int				recursive(t_tetriminos **lst, char **grid, char c);
int				insert_ok(t_tetriminos **lst, char **grid, char c);
int				return_check(int check, int free, t_tetriminos **lst,
															char **tetrimino);
int				**allocate_pos(t_tetriminos **lst, char **grid);
void			exit_error(char **grid, t_tetriminos **lst);

#endif
