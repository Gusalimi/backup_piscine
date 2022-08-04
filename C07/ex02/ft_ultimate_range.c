/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:11:22 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/24 12:13:00 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	i;
	unsigned int	len;
	int				*tab;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	i = 0;
	len = max - min;
	tab = malloc(sizeof(int) * len);
	while (i < len)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	if (tab != 0)
		return (len);
	else
		return (-1);
}
