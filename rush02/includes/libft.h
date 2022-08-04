/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:00:47 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/30 12:48:11 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

char	**ft_split(char *str, char *charset);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
void	ft_putchar_fd(int fd, char c);
void	ft_swap(int *a, int *b);
void	ft_putstr_fd(int fd, char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
