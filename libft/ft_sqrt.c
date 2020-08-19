/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:57:53 by jpalgi            #+#    #+#             */
/*   Updated: 2020/07/07 15:34:02 by jpalgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;
	int result;

	if (nb < 0 || 2147395600 < nb)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	i = 2;
	result = i * i;
	while (result <= nb && i - 1 != 46340)
	{
		i++;
		result = i * i;
	}
	i -= 1;
	if (i * i != nb)
		return (0);
	return (i);
}
