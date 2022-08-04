/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:48:09 by gsaile            #+#    #+#             */
/*   Updated: 2022/08/03 16:11:50 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "to_letters.h"
#include "libft.h"
#include "parse.h"

int	is_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char	*power_ten(char c, int len)
{
	char	*ret;
	int		j;

	ret = malloc((len + 2) * sizeof(char));
	ret[0] = c;
	ret[1] = 0;
	j = 0;
	while (j < len)
	{
		ft_strncat(ret, "0", 1);
		j++;
	}
	return (ret);
}

void	putstr_space(int space, char *str)
{
	if (space)
		ft_putchar_fd(1, ' ');
	ft_putstr_fd(1, str);
}

void	norme(t_pair **dict, char **strs, int i, int *j)
{
	int	size;

	size = find_size(strs);
	while ((*j) < ft_strlen(strs[i]))
	{
		if (!(strs[i][*j] == '0'))
		{
			if (ft_strlen(&strs[i][*j]) == 1 || ft_strlen(&strs[i][*j]) == 3)
				putstr_space(i + *j, name(dict, char_to_str(strs[i][*j])));
			if (ft_strlen(&strs[i][*j]) == 2)
			{
				if (strs[i][*j] < '2')
					putstr_space(i + *j, name(dict, &strs[i][(*j)++]));
				else
					putstr_space(i + *j, name(dict, power_ten(strs[i][*j],
								ft_strlen(&strs[i][*j]) - 1)));
			}
			if (ft_strlen(&strs[i][*j]) == 3)
				putstr_space(1, name(dict, "100"));
		}
		(*j)++;
	}
	if (ft_strcmp(name(dict, power_ten('1', (size - i - 1) * 3)), "one") != 0)
		putstr_space(i + *j, name(dict, power_ten('1', (size - i - 1) * 3)));
}

void	to_letters(t_pair **dict, char *nbr)
{
	int		i;
	int		j;
	int		size;
	char	**strs;

	strs = nbr_to_tab(nbr);
	size = find_size(strs);
	if (size == 1 && nbr[0] == '0')
	{
		ft_putstr_fd(1, name(dict, "0"));
		ft_putchar_fd(1, '\n');
		return ;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		if (!is_zero(strs[i++]))
			norme(dict, strs, i - 1, &j);
	}
	ft_putchar_fd(1, '\n');
}
