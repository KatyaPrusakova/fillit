/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 13:00:07 by jpalgi            #+#    #+#             */
/*   Updated: 2020/06/12 14:25:51 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lexicographically compare the null-terminated strings s1 and s2.
**
** Return an integer greater than, equal to, or less than 0, according as the
** string s1 is greater than, equal to, or less than the string s2.
** The comparison is done using unsigned characters, so that `\200' is greater
** than `\0'.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (s1[i] != s2[i])
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
