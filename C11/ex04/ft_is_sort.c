/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:25:03 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/28 17:41:09 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	is_sort_up;
	int	is_sort_down;

	i = 1;
	is_sort_up = 1;
	is_sort_down = 1;
	while (i < length)
	{
		if ((*f)(tab[i - 1], tab[i]) > 0)
			is_sort_up = 0;
		if ((*f)(tab[i - 1], tab[i]) < 0)
			is_sort_down = 0;
		i++;
	}
	return (is_sort_up || is_sort_down);
}
