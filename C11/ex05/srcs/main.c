/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:47:28 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/28 19:59:01 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/libft.h"
#include "../includes/operators.h"

int	(*ft_find_operator(char operator))(int x, int y)
{
	if (operator == '+')
		return (&ft_add);
	if (operator == '-')
		return (&ft_subtract);
	if (operator == '*')
		return (&ft_multiply);
	if (operator == '/')
		return (&ft_divide);
	if (operator == '%')
		return (&ft_modulo);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	if (ft_strlen(argv[2]) > 1 || !ft_find_operator(argv[2][0]))
	{
		write(1, "0\n", 2);
		return (1);
	}
	if (ft_atoi(argv[3]) == 0)
	{
		if (argv[2][0] == '/')
		{
			ft_putstr_fd(1, "Stop : division by zero\n");
			return (1);
		}	
		else if (argv[2][0] == '%')
		{
			ft_putstr_fd(1, "Stop : modulo by zero\n");
			return (1);
		}
	}
	ft_putnbr(ft_find_operator(argv[2][0])(ft_atoi(argv[1]), ft_atoi(argv[3])));
	ft_putchar_fd(1, '\n');
}
