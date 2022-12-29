/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:33:58 by saeby             #+#    #+#             */
/*   Updated: 2022/12/28 23:39:20 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = begin_list;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

/* 
Not quite sure if this work but it should
this one is recursive, and the first one is iterative

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (ft_list_size(begin_list->next) + 1);
}
*/