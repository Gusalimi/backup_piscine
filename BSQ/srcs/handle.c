/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abitonti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:59:06 by abitonti          #+#    #+#             */
/*   Updated: 2022/08/03 23:47:33 by abitonti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "t_tab.h"

int	ft_atoi(char *str, int n);

int	getcharset(t_tab *tab, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		if (str[i] < ' ' || str[i] == 127)
			return (0);
		j = 0;
		while (j < i)
		{
			if (str[i] == str[j++])
				return (0);
		}
		tab->charset[i] = str[i];
		i++;
	}
	return (1);
}

char	*getparam(int file, t_tab *tab, char *buff)
{
	int		n;
	int		i;

	tab->col = 0;
	i = 0;
	n = read(file, &buff[i], 1);
	while (n == 1 && buff[i] != '\n' && i < BUFFSIZE - 1)
		n = read(file, &buff[++i], 1);
	if (!n || i == BUFFSIZE - 1)
		return (0);
	tab->line = ft_atoi(buff, i - 3);
	if (tab->line == 0)
		return (0);
	if (!getcharset(tab, &buff[i - 3]))
		return (0);
	i = 0;
	n = read(file, &buff[i], 1);
	while (n == 1 && buff[i] != '\n' && i < BUFFSIZE - 1)
		n = read(file, &buff[++i], 1);
	if (!n || i == 0 || i == BUFFSIZE - 1)
		return (0);
	tab->col = i;
	return (buff);
}

t_obstacle	**setnextobs(t_obstacle **nextobs, int l, int c)
{
	*nextobs = malloc(sizeof(t_obstacle));
	if (!(*nextobs))
		return (0);
	(*nextobs)->line = l;
	(*nextobs)->col = c;
	(*nextobs)->next = 0;
	return (&((*nextobs)->next));
}

t_obstacle	**initobs(t_tab *tab)
{
	t_obstacle	**nextobs;

	nextobs = setnextobs(&(tab->firstobs), -1, tab->col);
	nextobs = setnextobs(nextobs, tab->line, -1);
	nextobs = setnextobs(nextobs, tab->line, tab->col);
	return (nextobs);
}

int	gettab(int file, t_tab *tab, char *buff, int l)
{
	int			i;
	t_obstacle	**nextobs;

	if (!buff)
		return (0);
	tab->grid = malloc(tab->line * sizeof(char *));
	nextobs = initobs(tab);
	while (!l || read(file, buff, tab->col + 1) == tab->col + 1)
	{
		tab->grid[l] = malloc(tab->col * sizeof(char));
		i = -1;
		while (++i < tab->col)
		{
			tab->grid[l][i] = buff[i];
			if (buff[i] == tab->charset[1])
				nextobs = setnextobs(nextobs, l, i);
			else if (buff[i] != tab->charset[0])
				return (0);
		}
		if (buff[i] != '\n')
			return (0);
		if (++l == tab->line)
			return (1);
	}
	return (0);
}
