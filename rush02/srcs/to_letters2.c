/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_letters2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:41:46 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/31 16:04:40 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "to_letters.h"
#include "libft.h"
#include "parse.h"

int	is_power_ten(char *nbr)
{
	int	i;

	if (ft_strlen(nbr) < 3 || nbr[0] != '1')
		return (0);
	i = 1;
	while (nbr[i])
	{
		if (nbr[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char	**nbr_to_tab(char *nbr)
{
	int		i;
	int		j;
	char	**strs;

	i = 0;
	j = 0;
	strs = malloc(((ft_strlen(nbr) / 3) + 2) * sizeof(char *));
	if (ft_strlen(nbr) % 3 != 0)
	{
		strs[0] = malloc(((ft_strlen(nbr) % 3) + 1) * sizeof(char));
		while (ft_strlen(nbr) % 3 != 0)
			strs[0][i++] = *(nbr++);
		strs[0][i] = 0;
		j = 1;
	}
	while (*nbr)
	{
		i = 0;
		strs[j] = malloc(4 * sizeof(char));
		while (i < 3)
			strs[j][i++] = *(nbr++);
		strs[j++][i] = 0;
	}
	strs[j] = 0;
	return (strs);
}

char	*char_to_str(char c)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	str[0] = c;
	str[1] = '\0';
	return (str);
}

int	find_size(char **strs)
{
	int	size;

	size = 0;
	while (strs[size])
		size++;
	return (size);
}

char	*name(t_pair **dict, char *nbr)
{
	int	i;

	i = 0;
	while (dict[i + 1])
	{
		if (ft_strcmp(dict[i]->nb, nbr) == 0)
			return (dict[i]->name);
		i++;
	}
	return ("NOPE");
}
