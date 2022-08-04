/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:41:44 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/27 12:16:50 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if ((str[i + 1] == '\0' || ft_is_in_charset(str[i + 1], charset))
			&& (!ft_is_in_charset(str[i], charset)))
			c++;
		i++;
	}
	return (c);
}

char	*ft_create_str(int i, char *src)
{
	int		k;
	char	*str;

	k = 0;
	str = malloc((i + 1) * sizeof(char));
	while (k < i)
	{
		str[k] = src[k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

void	ft_trim_charset(char **str, char *charset)
{
	while (ft_is_in_charset(**str, charset))
		(*str)++;
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc((ft_count_words(str, charset) + 1) * sizeof(char *));
	ft_trim_charset(&str, charset);
	while (str[i])
	{
		if ((str[i + 1] == '\0' || ft_is_in_charset(str[i + 1], charset))
			&& (!ft_is_in_charset(str[i], charset)))
		{
			ret[j] = ft_create_str(++i, str);
			j++;
			str += i;
			i = 0;
			ft_trim_charset(&str, charset);
		}
		else
			i++;
	}
	ret[j] = 0;
	return (ret);
}
