/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:32:43 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/28 10:40:38 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int	*tab, int length, int (*f)(int))
{
	int	*ret;
	int	i;

	ret = malloc(length * sizeof(*tab));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < length)
	{
		ret[i] = (*f)(tab[i]);
		i++;
	}
	return (ret);
}
