/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:36:29 by gsaile            #+#    #+#             */
/*   Updated: 2022/08/03 15:45:59 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
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

void	ft_putnbr_base(int nbr, char *base, char *str)
{
	unsigned int	value;
	unsigned int	nb;
	char			minus;

	value = ft_strlen(base);
	if (!ft_is_valid(base))
		return ;
	if (nbr < 0)
	{
		minus = '-';
		ft_strncat(str, &minus, 1);
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb >= value)
	{
		ft_putnbr_base(nb / value, base, str);
		ft_putnbr_base(nb % value, base, str);
	}
	else
		ft_strncat(str, &base[nb], 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	base_len;
	unsigned int	size;
	long int		tmp;
	char			*ret;
	int				dec;

	base_len = ft_strlen(base_to);
	dec = ft_atoi_base(nbr, base_from);
	size = 1;
	tmp = 1;
	while (tmp < dec)
	{
		tmp *= base_len;
		size++;
	}
	ret = malloc(size * sizeof(char));
	ft_putnbr_base(dec, base_to, ret);
	return (ret);
}
