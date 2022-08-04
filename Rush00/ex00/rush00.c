/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:23:55 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/16 16:49:19 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Makes ft_putchar usable in rush
void	ft_putchar(char c);

void	ft_print_line(int x, char f_c, char m_c, char l_c)
{
	int	i;

	if (x > 0)
		ft_putchar(f_c);
	i = 1;
	while (i < x - 1)
	{
		ft_putchar(m_c);
		i++;
	}
	if (x > 1)
		ft_putchar(l_c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (y > 0)
		ft_print_line(x, 'o', '-', 'o');
	i = 1;
	while (i < y - 1)
	{
		ft_print_line(x, '|', ' ', '|');
		i++;
	}
	if (y > 1)
	{
		ft_print_line(x, 'o', '-', 'o');
	}
}
