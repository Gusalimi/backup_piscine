/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:47:28 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/28 18:24:52 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "libft.h"

void	ft_print_file(int fd, char *filename)
{
	char	c;

	if (fd == -1)
	{
		ft_putstr_fd(2, "cat: ");
		ft_putstr_fd(2, filename);
		ft_putstr_fd(2, ": ");
		ft_putstr_fd(2, strerror(errno));
		ft_putchar_fd(2, '\n');
	}
	else
	{
		while (read(fd, &c, 1) > 0)
		{
			write(1, &c, 1);
		}
	}
}

void	ft_is_directory(char *filename)
{
	ft_putstr_fd(2, "cat: ");
	ft_putstr_fd(2, filename);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, strerror(21));
	ft_putchar_fd(2, '\n');
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc == 1)
	{
		ft_print_file(0, "");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			fd = 0;
		else if (open(argv[i], O_RDONLY | O_DIRECTORY) != -1)
		{
			ft_is_directory(argv[i++]);
			continue ;
		}
		else
			fd = open(argv[i], O_RDONLY);
		ft_print_file(fd, argv[i]);
		close(fd);
		i++;
	}
	return (0);
}
