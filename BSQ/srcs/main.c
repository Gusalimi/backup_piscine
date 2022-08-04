/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abitonti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 20:14:56 by abitonti          #+#    #+#             */
/*   Updated: 2022/08/03 23:48:30 by abitonti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "t_tab.h"

int		solve(t_tab tab, int sol[3]);

char	*getparam(int file, t_tab *tab, char *buff);

int		gettab(int file, t_tab *tab, char *buff, int l);

void	print_grid(t_tab tab)
{
	int	i;

	i = 0;
	while (i < tab.line)
	{
		write(1, tab.grid[i], tab.col);
		write(1, "\n", 1);
		i++;
	}
}

void	freetab(t_tab tab)
{
	int			i;
	t_obstacle	*nextobs;
	t_obstacle	*temp;

	if (tab.col == 0)
		return ;
	nextobs = tab.firstobs;
	while (nextobs)
	{
		temp = nextobs->next;
		free(nextobs);
		nextobs = temp;
	}
	i = -1;
	if (tab.grid)
	{
		while (++i < tab.line)
			if (tab.grid[i])
				free(tab.grid[i]);
		free(tab.grid);
	}
}

void	handle(int file)
{
	t_tab	tab;
	char	buff[BUFFSIZE];
	int		sol[3];

	sol[0] = 0;
	sol[1] = 0;
	sol[2] = 0;
	if (file == -1 && write(2, "map error\n", 10))
		return ;
	if (!gettab(file, &tab, getparam(file, &tab, buff), 0))
	{
		close(file);
		freetab(tab);
		write(2, "map error\n", 10);
		return ;
	}
	close(file);
	solve(tab, sol);
	print_grid(tab);
	freetab(tab);
}

int	main(int argc, char **argv)
{
	int		file;
	int		i;

	i = 0;
	while (++i < argc || i == 1)
	{
		if (argc == 1)
			file = 0;
		else
			file = open(argv[i], O_RDONLY);
		if (file != -1)
			handle(file);
		else
			write(2, "map error\n", 10);
	}
	return (0);
}
