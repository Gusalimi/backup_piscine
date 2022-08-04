/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:19:32 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/15 11:09:30 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	buffer;

	i = 0;
	while (i < size / 2)
	{
		buffer = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = buffer;
		i++;
	}
}
