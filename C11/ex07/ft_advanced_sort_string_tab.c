/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:04:35 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/29 12:39:27 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_size(char **tab)
{
	int	i;

	i = 0;
	while (*tab)
	{
		i++;
		tab++;
	}
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*min;
	int		size;

	i = 0;
	size = ft_find_size(tab);
	while (i < size)
	{
		min = tab[i];
		j = i + 1;
		while (j < size)
		{
			if ((*cmp)(tab[j], min) < 0)
			{
				min = tab[j];
				tab[j] = tab[i];
				tab[i] = min;
			}
			j++;
		}
		i++;
	}
}
