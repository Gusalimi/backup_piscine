/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abitonti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:12:30 by abitonti          #+#    #+#             */
/*   Updated: 2022/08/02 13:14:16 by abitonti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_tab.h"
#include <stdlib.h>

int	max(int a, int b, int n);

int	min(int a, int b);

void	genpoint(t_obstacle *obs, t_obstacle *next, t_point *tpoint)
{
	int	l;
	int	c;

	if (obs->line == next->line || obs->col == next->col)
		return ;
	l = min(obs->line, next->line) + 1;
	c = min(obs->col, next->col) + 1;
	while (tpoint)
	{
		if (tpoint->line == l && tpoint->col == c)
			return ;
		if (tpoint->next == 0)
		{
			tpoint->next = malloc(sizeof(t_point));
			tpoint->next->line = l;
			tpoint->next->col = c;
			tpoint->next->next = 0;
			break ;
		}
		tpoint = tpoint->next;
	}
}

void	getsol(t_tab tab, t_point *tpoint, int sol[3])
{
	t_obstacle	*obs;
	int			n;
	int			nmin;

	while (tpoint)
	{
		obs = tab.firstobs;
		nmin = min(tab.line - tpoint->line, tab.col - tpoint->col);
		while (obs)
		{
			n = max(obs->line - tpoint->line, obs->col - tpoint->col, nmin);
			if (n >= 0 && n < nmin)
				nmin = n;
			obs = obs->next;
		}
		if (nmin > sol[2] || (nmin == sol[2] && (tpoint->line < sol[0]
					|| (tpoint->line == sol[0] && tpoint->col < sol[1]))))
		{
			sol[2] = nmin;
			sol[0] = tpoint->line;
			sol[1] = tpoint->col;
		}
		tpoint = tpoint->next;
	}
}

void	putsol(t_tab tab, int sol[3])
{
	int	l;
	int	c;

	l = 0;
	while (l < sol[2])
	{
		c = 0;
		while (c < sol[2])
		{
			tab.grid[sol[0] + l][sol[1] + c] = tab.charset[2];
			c++;
		}
		l++;
	}
}

void	freepoint(t_point firstpoint)
{
	t_point	*nextpoint;
	t_point	*temp;

	nextpoint = firstpoint.next;
	while (nextpoint)
	{
		temp = nextpoint->next;
		free(nextpoint);
		nextpoint = temp;
	}
}

int	solve(t_tab tab, int sol[3])
{
	t_point		firstpoint;
	t_obstacle	*obs;
	t_obstacle	*nextobs;

	firstpoint.line = 0;
	firstpoint.col = 0;
	firstpoint.next = 0;
	obs = tab.firstobs;
	while (obs)
	{
		nextobs = obs->next;
		while (nextobs)
		{
			genpoint(obs, nextobs, &firstpoint);
			nextobs = nextobs->next;
		}
		obs = obs->next;
	}
	getsol(tab, &firstpoint, sol);
	freepoint(firstpoint);
	putsol(tab, sol);
	return (0);
}
