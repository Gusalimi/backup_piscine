/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:28:17 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/31 20:41:41 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_pair
{
	char	*nb;
	char	*name;
}	t_pair;

t_pair	*parse_line(char *line);
t_pair	**open_dict(char *filename);
char	*file_str(int fd, int size);
void	trim_spaces_and_colon(char **str);
int		file_len(char *filename);

#endif
