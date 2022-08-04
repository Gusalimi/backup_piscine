/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:18:36 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/31 21:24:53 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"
#include "libft.h"

int	count_lines(t_pair **dict)
{
	int		i;

	i = 0;
	while (dict[i])
		i++;
	return (i);
}

int	error_msg(void)
{
	ft_putstr_fd(2, "Error\n");
	return (1);
}
