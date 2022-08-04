/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:28:45 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/19 14:46:21 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(const int dec)
{
	ft_putchar('\\');
	ft_putchar("0123456789abcdef"[dec / 16]);
	ft_putchar("0123456789abcdef"[dec % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32)
		{
			ft_print_hex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
