/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:37:42 by gsaile            #+#    #+#             */
/*   Updated: 2022/08/03 15:27:04 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	len;

	if (min >= max)
		return (NULL);
	len = max - min;
	tab = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
