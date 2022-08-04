/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:47:28 by gsaile            #+#    #+#             */
/*   Updated: 2022/08/03 13:50:05 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include "../includes/libft.h"

#include <stdio.h>

void	ft_print_header(char *filename)
{
	ft_putstr_fd(1, "==> ");
	ft_putstr_fd(1, filename);
	ft_putstr_fd(1, " <==\n");
}

void	ft_print_file(int fd, char **filenames, int first_character, int has_header)
{
	char	c;
	int		i;

	if (fd == -1)
	{
		//if (has_header)
		//{
			ft_putstr_fd(2, basename(filenames[0]));
			ft_putstr_fd(2, ": ");
			ft_putstr_fd(2, filenames[1]);
			ft_putstr_fd(2, ": ");
			ft_putstr_fd(2, strerror(errno));
			ft_putchar_fd(2, '\n');
		//}
		return ;
	}
	if (has_header)
		ft_print_header(filenames[1]);
	i = 0;
	while (i++ < first_character)
		read(fd, &c, 1);
	while (read(fd, &c, 1))
		write(1, &c, 1);
}

int	ft_first_character(char **filenames, int flag)
{
	char	c;
	int		fd;
	int		i;

	i = 0;
	fd = open(filenames[1], O_RDONLY);
	if (fd == -1)
	{
		ft_print_file(fd, filenames, 0, 0);
		return (-1);
	}
	while(read(fd, &c, 1))
		i++;
	if (i - flag > 0)
		i -= flag;
	else
		i = 0;
	return (i);
}

void	ft_is_directory(char *filename)
{
	ft_print_header(filename);
	ft_putstr_fd(1, "\n");
}


void	ft_handle_stdin(int flag)
{
	char	str[1000000];
	char	c;

	str[0] = 0;
	while (read(0, &c, 1))
	{
		ft_strncat(str, &c, 1);
	}
	if (ft_strlen(str) - flag > 0)
		ft_putstr_fd(1, &str[ft_strlen(str) - flag]);
	else
		ft_putstr_fd(1, str);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		has_header;
	int		flag;
	char	*names[2];

	has_header = 1;
	if (argc == 4)
		has_header = 0;
	flag = ft_atoi(argv[2]);
	if (argc == 3)
	{
		ft_handle_stdin(flag);
		return (0);
	}
	if (argc < 3)
	{
		ft_putstr_fd(2, "Usage : ./ft_tail -c [number] [files...]\n");
		return (1);
	}
	i = 3;
	while (i < argc)
	{
		if (open(argv[i], O_RDONLY | O_DIRECTORY) != -1)
		{
			ft_is_directory(argv[i++]);
			continue ;
		}
		else
			fd = open(argv[i], O_RDONLY);
		names[0] = argv[0];
		names[1] = argv[i];
		ft_print_file(fd, names, ft_first_character(names, flag), has_header);
		if (i + 1 < argc)
			write(1, "\n", 1);
		close(fd);
		i++;
	}
	return (0);
}
