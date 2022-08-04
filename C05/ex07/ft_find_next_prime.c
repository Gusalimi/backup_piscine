/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:03:37 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/20 18:18:54 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb, long int i)
{
	if (i * i > nb)
		return (i - 1);
	return (ft_sqrt(nb, i + 1));
}

int	ft_rec_is_prime(int nb, int i, int sqrt)
{
	if (nb < 2)
		return (0);
	if (i > sqrt)
		return (1);
	if (nb % i == 0)
		return (0);
	return (ft_rec_is_prime(nb, i + 1, sqrt));
}

int	ft_is_prime(int nb)
{
	return (ft_rec_is_prime(nb, 2, ft_sqrt(nb, 0)));
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	return (ft_find_next_prime(nb + 1));
}
