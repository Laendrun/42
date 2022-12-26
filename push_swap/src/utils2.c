/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:36:18 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 19:29:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ps_ptr_to_min(t_dlist *a)
{
	t_dlist	*tmp;
	t_dlist	*min_ptr;
	long	min_val;

	tmp = a;
	min_val = a->content;
	min_ptr = tmp;
	while (tmp)
	{
		if (tmp->content < min_val)
		{
			min_ptr = tmp;
			min_val = tmp->content;
		}
		tmp = tmp->next;
	}
	return (min_ptr);
}

t_dlist	*ps_ptr_to_max(t_dlist *a)
{
	t_dlist	*tmp;
	t_dlist	*max_ptr;
	long	max_val;

	tmp = a;
	max_val = a->content;
	max_ptr = a;
	while (tmp)
	{
		if (tmp->content > max_val)
		{
			max_ptr = tmp;
			max_val = tmp->content;
		}
		tmp = tmp->next;
	}
	return (max_ptr);
}
