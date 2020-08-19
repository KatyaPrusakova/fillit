/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:44:46 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/30 18:16:40 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/*
** Frees list element (text and element itself) if element->fd == fd.
** Clears whole list when clear_all == 1.
*/

static int		free_lst_t_file(t_file **head, int clear_all, int fd)
{
	t_file *curr;
	t_file *prev;

	prev = NULL;
	curr = (head && *head) ? *head : NULL;
	while (curr)
	{
		if ((curr->fd == fd) || clear_all)
		{
			if (curr->fd == (*head)->fd)
				*head = curr->next;
			else
				prev->next = curr->next;
			ft_strdel(&curr->text);
			ft_memdel((void **)&curr);
			if (clear_all)
				return (free_lst_t_file(head, 1, fd));
			else
				return (1);
		}
		prev = curr;
		curr = curr->next;
	}
	return (-1);
}

/*
** Returns a t_file struct pointer. If given t_file pointer with fd doesnt exist
** its created and returned. If t_file already exists then the new t_file
** pointer with the fd value is appended to the list.
*/

static t_file	*select_t_file(int fd, t_file *file)
{
	t_file	*temp;

	if (!file)
	{
		if (!(temp = (t_file *)ft_memalloc(sizeof(t_file))))
			return (NULL);
		temp->fd = fd;
		temp->next = NULL;
		return (temp);
	}
	if (file->fd == fd)
		return (file);
	temp = file;
	while (temp->next)
	{
		if (temp->next->fd == fd)
			return (temp->next);
		temp = temp->next;
	}
	temp->next = select_t_file(fd, NULL);
	return (temp->next);
}

/*
** Allocates and returns a new string starting from the start of the *text until
** the endof_line ('\0' or '\n' not included) char is found. *text is made
** shorter by making a new str from after the found endof_line to the end of
** the *text.
*/

static char		*newline_found(char **text, char endof_line)
{
	int		len;
	char	*newstr;
	char	*temp;

	len = 0;
	while ((*text)[len] != endof_line)
		len++;
	if (!(newstr = ft_strnew(len + 1)))
		return (NULL);
	if (len != 0 && !ft_strnequ(*text, "\n", len))
		ft_strncpy(newstr, *text, len);
	newstr[len] = '\0';
	if (!(temp = ft_strndup(&((*text)[len + 1]), ft_strlen(*text) - len)))
		return (NULL);
	ft_strdel(text);
	*text = temp;
	return (newstr);
}

/*
** file->text is joined with buf every time buf is read and after which the buf
** is freed. Returns 1 and assigns line if a line ending with '\n' is found or
** end of file is found '\0'. Else returns 0. On error returns -1.
*/

static int		check_buf(t_file *file, char *buf, int ret, char **line)
{
	char *temp;

	temp = file->text;
	if (ret != 0 && !(file->text = ft_strjoin(file->text, buf)))
	{
		ft_strdel(&temp);
		return (-1);
	}
	if (ret != 0 && temp)
		ft_strdel(&temp);
	ft_strdel(&buf);
	if (file->text && ft_strchr(file->text, '\n'))
	{
		if (!(*line = newline_found(&file->text, '\n')))
			return (-1);
		return (1);
	}
	if (file->text && ret == 0 && file->text[0] != '\0')
	{
		if ((!(*line = newline_found(&file->text, '\0'))))
			return (-1);
		return (1);
	}
	return (0);
}

/*
** File will be read and the buffer for it will be checked. Function will call
** itself until a line has been read (ending with '\n' or the end of the file
** '\0'). *line is never freed, pointer is over written on every line.
** The return value can be 1, 0 or -1 depending on whether a line has been read,
** when the reading has been completed, or if an error has happened respectively
*/

int				get_next_line(const int fd, char **line)
{
	static t_file	*file;
	t_file			*file_temp;
	char			*buf;
	int				ret;
	int				num;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || !(buf = ft_strnew(BUFF_SIZE + 1))
		|| (!file && !(file = select_t_file(fd, file))))
		return ((file && fd != -1) ? free_lst_t_file(&file, 1, -1) : -1);
	file_temp = (file && file->fd != fd) ? select_t_file(fd, file) : file;
	if (!file_temp || (ret = read(file_temp->fd, buf, BUFF_SIZE)) == -1)
		return (free_lst_t_file(&file, 1, -1));
	if ((num = check_buf(file_temp, buf, ret, line)) == 1)
		return (1);
	if ((ret != 0 && ret != -1 && num != -1) ||
		(num != 0 && num != -1 && file->text))
		return (get_next_line(file_temp->fd, line));
	else
	{
		free_lst_t_file(&file, 0, file_temp->fd);
		return (ret);
	}
}
