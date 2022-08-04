/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:06:45 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/25 10:32:44 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ret;
	int			i;

	i = 0;
	ret = malloc ((ac + 1) * sizeof(t_stock_str));
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = *(&av[i]);
		ret[i].copy = malloc((ft_strlen(av[i]) + 1) * sizeof(char));
		ft_strcpy(ret[i].copy, av[i]);
		i++;
	}
	ret[i].size = 0;
	ret[i].str = 0;
	ret[i].copy = 0;
	if (ret == 0)
		return (NULL);
	return (ret);
}
