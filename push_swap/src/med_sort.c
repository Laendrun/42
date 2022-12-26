/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:02:58 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 17:41:55 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*ps_med_sort(t_lists *stacks)
{
	int	pivot_i;
	int	i;
	int	pivot_value;
	int	size;
	t_dlist	*tmp;

	size = ps_lstsize(stacks->a);
	pivot_i = size / 2;
	pivot_value = ps_get_value_index(stacks->a, pivot_i);
	i = 0;
	while (i < size)
	{
		tmp = ps_lstfirst(stacks->a);
		if (tmp->content >= pivot_value)
			stacks = ps_pb(stacks);
		else if (tmp->content < pivot_value)
			stacks = ps_ra(stacks);
		//ft_printf("---b---\n");
		//ps_lstprint(stacks->b);
		i++;
	}
	
	return (stacks);
}