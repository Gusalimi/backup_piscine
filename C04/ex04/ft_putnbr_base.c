/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:36:29 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/20 16:34:36 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

int	ft_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (ft_strlen(base) > 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	value;
	unsigned int	nb;

	value = ft_strlen(base);
	if (!ft_is_valid(base))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb >= value)
	{
		ft_putnbr_base(nb / value, base);
		ft_putnbr_base(nb % value, base);
	}
	else
		ft_putchar(base[nb]);
}
