/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:47:28 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/28 18:29:17 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	c;

	if (argc == 1)
	{
		ft_putstr_fd(2, "File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr_fd(2, "Too many arguments.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(2, "Cannot read file.\n");
		return (1);
	}
	while (read(fd, &c, 1) > 0)
	{
		write(1, &c, 1);
	}
	close(fd);
	return (0);
}
