/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 19:32:41 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/12 11:38:21 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates (with malloc(3)) and returns an list of “fresh” strings (all ending
** with ’\0’) obtained by spliting s using the character c as a delimiter. If
** the allocation fails the function returns NULL. Example:
** ft_strsplit_lst("*hello*fellow***students*", ’*’)
** returns the list "hello", "fellow", "students"
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

t_list		*ft_lst_strsplit(char const *s, char c)
{
	int		i;
	int		substrings;
	int		lens[50];
	t_list	*head;
	t_list	*temp;

	count_str(s, c, &substrings, lens);
	i = 0;
	head = NULL;
	while (i < substrings)
	{
		while (*s == c)
			s++;
		if (!(temp = ft_lstnew((void *)s, lens[i] + 1)) ||
			!(temp = ft_lstadd_toend(&head, temp)))
		{
			ft_lstfree(&head);
			return (NULL);
		}
		((char *)temp->content)[lens[i]] = '\0';
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	return (head);
}
