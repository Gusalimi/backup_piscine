/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:08:29 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/28 11:46:58 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isspace(char c)
{
	return (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ');
}

int	base_length(char *base)
{
	int	base_len;
	int	i;
	int	j;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (base_len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || ft_isspace(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (base_len);
}

int	is_in_base(char c, char *base)
{
	while (*base)
	{
		if (c == *base)
			return (1);
		base++;
	}
	return (0);
}

int	position(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int				base_len;
	int				nb_minus;
	int				sign;
	unsigned int	result;

	base_len = base_length(base);
	nb_minus = 0;
	sign = 1;
	result = 0;
	if (base_len == 0)
		return (0);
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			nb_minus++;
		str++;
	}
	while (is_in_base(*str, base))
		result = result * base_len + position(*(str++), base);
	if (nb_minus % 2 != 0)
		sign = -1;
	return (result * sign);
}
