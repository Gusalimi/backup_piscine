/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:42:17 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/28 20:00:43 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operators.h"

int	ft_add(int x, int y)
{
	return (x + y);
}

int	ft_subtract(int x, int y)
{
	return (x - y);
}

int	ft_multiply(int x, int y)
{
	return (x * y);
}

int	ft_divide(int x, int y)
{
	return (x / y);
}

int	ft_modulo(int x, int y)
{
	return (x % y);
}
