/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:53:24 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/18 15:10:33 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == 0 || i == n)
			return (0);
		i++;
	}
	if (s1[i] < s2[i])
		return (-1);
	else
		return (1);
}

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

char	*ft_strstr(char *str, char *to_find)
{
	if (ft_strlen(to_find) == 0)
		return (str);
	while (*str != '\0')
	{
		if (*str == to_find[0])
		{
			if (ft_strncmp(str, to_find, ft_strlen(to_find) - 1) == 0)
			{
				return (str);
			}
		}
		str++;
	}
	return (0);
}
