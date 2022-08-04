/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:00:47 by gsaile            #+#    #+#             */
/*   Updated: 2022/08/02 19:59:10 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void	ft_putchar_fd(int fd, char c);
void	ft_putstr_fd(int fd, char *str);
void	ft_swap(int *a, int *b);
char    *ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);

#endif
