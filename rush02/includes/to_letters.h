/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_letters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:48:36 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/31 20:23:39 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef TO_LETTERS_H
# define TO_LETTERS_H
# include "parse.h"

char	*name(t_pair **dict, char *nbr);
char	*power_ten(char c, int len);
char	**nbr_to_tab(char *nbr);
char	*char_to_str(char c);
void	norme(t_pair **dict, char **strs, int i, int *j);
void	putstr_space(int space, char *str);
void	to_letters(t_pair **dict, char *nbr);
int		is_power_ten(char *nbr);
int		find_size(char **strs);
int		is_zero(char *str);

#endif
