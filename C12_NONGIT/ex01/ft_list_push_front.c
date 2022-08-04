/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:07:26 by gsaile            #+#    #+#             */
/*   Updated: 2022/07/29 14:29:04 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	elem->next = *begin;
	*begin = elem;
}
