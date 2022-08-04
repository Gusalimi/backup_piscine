/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abitonti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:59:06 by abitonti          #+#    #+#             */
/*   Updated: 2022/08/01 23:24:06 by abitonti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "t_tab.h"

int	ft_atoi(char *str, int n)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (i < n)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	max(int a, int b, int n)
{
	if (a < 0 || b < 0)
		return (n);
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
