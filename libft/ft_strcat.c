/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:48:08 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/08 14:15:42 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Append a copy of the null-terminated string s2 to the end of the
** null-terminated string s1, then add a terminating `\0'. The string s1 must
** have sufficient space to hold the result.
**
** Return the pointer s1.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
