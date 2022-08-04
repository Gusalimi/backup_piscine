/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:21:35 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/25 13:42:53 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(char **tab, int size)
{
	int		i;
	int		j;
	char	*min;

	i = 0;
	while (i < size)
	{
		min = tab[i];
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[j], min) < 0)
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

int	main(int argc, char **argv)
{
	int	i;

	ft_sort_params(argv + 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
