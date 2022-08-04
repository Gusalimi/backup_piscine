/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:33:28 by gsaile            #+#    #+#             */
/*   Updated: 2022/08/03 15:40:21 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	unsigned int	ret_size;
	char			*ret;
	int				i;

	if (size <= 0)
		return (malloc(sizeof(char)));
	ret_size = 0;
	i = 0;
	while (i < size)
		ret_size += ft_strlen(strs[i++]);
	ret_size += ft_strlen(sep) * (size - 1);
	ret = malloc((ret_size + 1) * sizeof(char));
	if (ret == 0)
		return (0);
	i = 0;
	ret[0] = '\0';
	while (i < size)
	{
		ft_strcat(ret, strs[i]);
		if (i < size - 1)
			ft_strcat(ret, sep);
		i++;
	}
	return (ret);
}
