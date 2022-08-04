/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:22:50 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/26 16:07:22 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int *nb, int n);

void	ft_inc_tab(int *nb, int n)
{
	int	i;

	i = 9;
	while (i > 9 - n)
	{
		nb[i]++;
	}
}

void	ft_print_combn(int n)
{
	int	nb[10];
	int	i;
	int	j;

	i = 9 - n;
	j = 0;
	while (i < n)
	{
		nb[i] = j;
		i++;
		j++;
	}
}
