/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:37:42 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/27 13:19:55 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

#include <stdio.h>
int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	len;

	if (min >= max)
		return (NULL);
	printf("OUI");
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

int	main(void)
{
	int	max = 22;
	int min = 23;
	//int len = max - min;
	if (ft_range(min, max))
	{
		int *tab = ft_range(min, max);
		for (int i = 0 ; i < 1 ; i++)
			printf("%d\n", tab[i]);
	}
	else
	{
		printf("Error\n");
	}
}
