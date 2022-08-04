/* ************************************************************************** */
/*o:::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:29:37 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/26 11:57:59 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (*str != '\0')
    {
        str++;
        i++;
    }
    return (i);
}

char    *ft_strcat(char *dest, char *src)
{
    int    i;
    int    j;

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

char    *ft_strjoin(int size, char **strs, char *sep)
{
    char            *ret;
    int                i;
    unsigned int    ret_size;

    if (size <= 0)
    {
        ret = malloc(sizeof(char));
        ret[0] = '\0';
        return (ret);
    }
    ret_size = 0;
    i = 0;
    while (i < size)
    {
        ret_size += ft_strlen(strs[i]);
        i++;
    }
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

#include <stdio.h>
int main(void)
{
  char *strs[] = { "Hello", "World", "!" };
  printf("%s\n", ft_strjoin(3, strs, " "));
  return (0);
}