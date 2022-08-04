/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:03:37 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/20 18:18:54 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_incr(char *str);

int	ft_check_line(char *str);

int	ft_check_diag(char *str);

int	ft_ten_queens_puzzle(void);
