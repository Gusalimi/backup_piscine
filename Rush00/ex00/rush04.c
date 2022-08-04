/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:23:55 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/17 18:34:25 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Makes ft_putchar usable in rush
void	ft_putchar(char c);

// f_c : first_character
// m_c : middle_character
// l_c : last_character
// Prints f_c if x > 0
// Prints m_c until there is only one character left to finish the line
// Prints l_c if x > 1
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

// Prints first line if y > 0
// Prints middle lines until there is only one line left to finish the rectangle
// Prints last line if y > 1
void	rush(int x, int y)
{
	int	i;

	if (y > 0)
		ft_print_line(x, 'A', 'B', 'C');
	i = 1;
	while (i < y - 1)
	{
		ft_print_line(x, 'B', ' ', 'B');
		i++;
	}
	if (y > 1)
	{
		ft_print_line(x, 'C', 'B', 'A');
	}
}
