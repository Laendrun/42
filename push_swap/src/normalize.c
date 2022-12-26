/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:28:23 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 18:24:31 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*ps_normalize(t_lists *stacks)
{
	int		i;
	int		size;
	t_dlist	*min;
	t_dlist	*max;

	i = 0;
	size = ps_lstsize(stacks->a);
	while (i < size)
	{
		min = ps_ptr_to_min(stacks->a);
		min->content = LONG_MAX - (1 + i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		max = ps_ptr_to_max(stacks->a);
		max->content = i;
		i++;
	}
	return (stacks);
}