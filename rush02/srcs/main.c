/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:16:26 by gsaile            #+#    #+#             */
/*   Updated: 2022/08/03 16:11:31 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parse.h"
#include "libft.h"
#include "to_letters.h"
#include "misc.h"

int	is_in_dict(char *str, t_pair **dict)
{
	int	i;

	i = 0;
	while (dict[i])
	{
		if (ft_strcmp(str, dict[i]->nb) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

char	*check_nb(char *nb)
{
	char	*ret;
	int		i;

	i = 0;
	while (nb[i + 1])
		if (nb[i++] == '.')
			return (0);
	while (ft_isspace(*nb))
		nb++;
	if (*nb == '-')
		return (0);
	if (*nb == '+')
		nb++;
	while (*nb == '0' && ft_strlen(nb) > 1)
		nb++;
	i = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
		i++;
	if (i > 0)
		ret = malloc((i + 1) * sizeof(char));
	else
		return (0);
	ret[0] = 0;
	ft_strncat(ret, nb, i);
	return (ret);
}

int	dict_is_valid(t_pair **dict)
{
	int		i;
	t_pair	**default_dict;

	i = 0;
	default_dict = open_dict("numbers.dict");
	if (default_dict == 0)
		return (1);
	while (default_dict[i])
	{
		if (!(is_in_dict(dict[i]->nb, default_dict)))
		{
			ft_putstr_fd(2, "Dict Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*filename;
	char	*nbr;
	t_pair	**dict;

	if (argc == 2)
		filename = "numbers.dict";
	else if (argc == 3)
		filename = argv[1];
	else
	{
		ft_putstr_fd(2, "usage: ./rush-02 [dictionary file] number\n");
		return (1);
	}
	nbr = check_nb(argv[argc - 1]);
	dict = open_dict(filename);
	if (dict == 0 || count_lines(open_dict("numbers.dict")) > count_lines(dict)
		|| !dict_is_valid(dict))
		ft_putstr_fd(2, "Dict Error\n");
	else if (argv[1][0] == '0' && argv[1][1] == '\0')
		write(1, "zero\n", 5);
	else if (nbr == 0)
		return (error_msg());
	else
		to_letters(dict, nbr);
}
