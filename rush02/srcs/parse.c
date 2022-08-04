/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:23:54 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/31 23:23:00 by mpankewi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "parse.h"
#include "libft.h"

void	trim_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
	(*str)++;
	while (**str == ' ')
		(*str)++;
}

// Turn the line in a struct containing the number and its prononciation
t_pair	*parse_line(char *line_str)
{
	t_pair	*line_struct;
	char	*nb_str;
	char	*name;
	int		i;

	i = 0;
	line_struct = malloc(sizeof(t_pair));
	while (line_str[i] != ' ' && line_str[i] != ':')
		i++;
	nb_str = malloc((i + 1) * sizeof(char));
	nb_str[0] = '\0';
	ft_strncat(nb_str, line_str, i);
	line_struct->nb = nb_str;
	line_str += i;
	trim_spaces(&line_str);
	i = 0;
	while (line_str[i])
		i++;
	name = malloc((i + 1) * sizeof(char));
	name[0] = '\0';
	ft_strncat(name, line_str, i);
	line_struct->name = name;
	return (line_struct);
}

// Read the file and put it in a string
char	*file_str(int fd, int size)
{
	int		i;
	char	*ret;
	char	c;

	i = 0;
	ret = malloc((size + 1) * sizeof(char));
	while (read(fd, &c, 1) > 0)
	{
		ret[i] = c;
		i++;
	}
	return (ret);
}

// Check if the file exists then count its length
int	file_len(char *filename)
{
	char	c;
	int		fd;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(2, "Dict Error\n");
		return (-1);
	}
	len = 0;
	c = 0;
	while (read(fd, &c, 1) > 0)
		len++;
	close(fd);
	return (len);
}

// Open the dict file, call the previous functions and create a temp dict file
// to get to the right line
t_pair	**open_dict(char *filename)
{
	int		fd;
	int		i;
	char	**line_strs;
	t_pair	**dict_struct;

	i = file_len(filename);
	if (i == -1)
		return (0);
	fd = open(filename, O_RDONLY);
	line_strs = ft_split(file_str(fd, i), "\n");
	i = 0;
	while (line_strs[i])
		i++;
	dict_struct = malloc((i + 1) * sizeof(t_pair *));
	i = 0;
	while (line_strs[i])
	{
		dict_struct[i] = parse_line(line_strs[i]);
		i++;
	}
	dict_struct[i] = 0;
	return (dict_struct);
}
