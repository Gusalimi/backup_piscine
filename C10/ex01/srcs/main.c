/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:47:28 by gsaile            #+#    #+#             */
/*   Updated: 2022/08/03 10:39:30 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include "libft.h"

void	ft_print_file(int fd, char *filename, int *ret_value, char *progName)
{
	char	c;

	if (fd == -1)
	{
		ft_putstr_fd(2, basename(progName));
		ft_putstr_fd(2, ": ");
		ft_putstr_fd(2, filename);
		ft_putstr_fd(2, ": ");
		ft_putstr_fd(2, strerror(errno));
		ft_putchar_fd(2, '\n');
		*ret_value = 1;
	}
	else
	{
		while (read(fd, &c, 1) > 0)
		{
			write(1, &c, 1);
		}
	}
}

int	ft_is_directory(char *filename, int *ret_value, char *progName)
{
	ft_putstr_fd(2, basename(progName));
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, filename);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, strerror(21));
	ft_putchar_fd(2, '\n');
	*ret_value = 1;
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		ret_value;

	ret_value = 0;
	if (argc == 1)
	{
		ft_print_file(0, "", &ret_value, argv[0]);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			fd = 0;
		else if (open(argv[i], O_RDONLY | O_DIRECTORY) != -1
			&& ft_is_directory(argv[i++], &ret_value, argv[0]))
			continue ;
		else
			fd = open(argv[i], O_RDONLY);
		ft_print_file(fd, argv[i++], &ret_value, argv[0]);
		if (fd != 0)
			close(fd);
	}
	return (ret_value);
}
