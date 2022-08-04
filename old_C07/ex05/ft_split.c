/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:32:50 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/26 11:20:38 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (str[i])
	{
		if (ft_is_in_charset(str[i], charset)
			&& !(ft_is_in_charset(str[i + 1], charset)))
			counter++;
		i++;
	}
	if (!ft_is_in_charset(str[i - 1], charset))
		counter++;
	return (counter);
}

char	*ft_create_tab(char *str, int i)
{
	char	*cpy;
	int		k;

	cpy = malloc((i + 1) * sizeof(char));
	k = 0;
	while (k < i)
	{
		cpy[k] = str[k];
		k++;
	}
	cpy[k] = '\0';
	return (cpy);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc((ft_count_words(str, charset) + 1) * sizeof (char *));
	while (str[i])
	{
		if (ft_is_in_charset(str[i], charset))
		{
			ret[j++] = ft_create_tab(str, i);
			str += i;
			i = 0;
			while (ft_is_in_charset(*str, charset))
				str++;
		}
		else
			i++;
	}
	if (!(ft_is_in_charset(str[i - 1], charset)))
		ret[j++] = ft_create_tab(str, i);
	ret[j] = 0;
	return (ret);
}
