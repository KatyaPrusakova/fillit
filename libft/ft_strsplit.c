/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 19:03:08 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/12 10:42:38 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates (with malloc(3)) and returns an array of “fresh” strings
** (all ending with ’\0’, including the array itself) obtained by spliting s
** using the character c as a delimiter. If the allocation fails the function
** returns NULL. Example: ft_strsplit("*hello*fellow***students*", ’*’)
** returns the array ["hello", "fellow", "students"].
*/

static void	count_str(char const *s, char c, int *strcount, int *lens)
{
	int i;
	int	end_without_delimiter;

	i = -1;
	while (++i < 50)
		lens[i] = 0;
	i = 0;
	*strcount = 0;
	end_without_delimiter = 1;
	while (s && s[i] != '\0')
	{
		if (i != 0 && s[i] == c && s[i - 1] != c)
		{
			(*strcount)++;
			end_without_delimiter = 0;
		}
		if (s[i] != c)
		{
			lens[*strcount]++;
			end_without_delimiter = 1;
		}
		i++;
	}
	if (lens[*strcount] != 0)
		*strcount += end_without_delimiter;
}

static void	free_arr(char **arr, int breakpoint)
{
	int j;

	j = 0;
	while (j < breakpoint)
	{
		free(arr[j]);
		arr[j] = NULL;
		j++;
	}
	free(arr);
	arr = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		substrings;
	int		lens[50];
	char	**arr;

	count_str(s, c, &substrings, lens);
	if (!s || (!(arr = (char **)malloc(sizeof(char *) * (substrings + 1)))))
		return (NULL);
	i = -1;
	while (++i < substrings)
	{
		if (!(arr[i] = ft_strnew(lens[i] + 1)))
		{
			free_arr(arr, i);
			return (NULL);
		}
		while (*s == c)
			s++;
		ft_strncpy(arr[i], s, lens[i]);
		arr[i][lens[i]] = '\0';
		while (*s != c && *s != '\0')
			s++;
	}
	arr[substrings] = 0;
	return (arr);
}
