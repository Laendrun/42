/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:14:18 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 13:04:43 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*ps_push_biggest_up_a(t_lists *stacks);
t_lists	*ps_push_biggest_up_b(t_lists *stacks);

t_lists	*ps_push_smallest_up_a(t_lists *stacks)
{
	int	sm_ind;

	sm_ind = ps_get_index(stacks->a, ps_get_min(stacks->a));
	if (sm_ind < ps_lstsize(stacks->a) / 2)
	{
		while (ps_lstfirst(stacks->a)->content != ps_get_min(stacks->a))
			stacks = ps_ra(stacks);
	}
	else
	{
		while (ps_lstfirst(stacks->a)->content != ps_get_min(stacks->a))
			stacks = ps_rra(stacks);
	}
	return (stacks);
}

t_lists	*ps_push_smallest_up_b(t_lists *stacks)
{
	int	sm_ind;

	sm_ind = ps_get_index(stacks->b, ps_get_min(stacks->b));
	if (sm_ind < ps_lstsize(stacks->b) / 2)
	{
		while (ps_lstfirst(stacks->b)->content != ps_get_min(stacks->b))
			stacks = ps_ra(stacks);
	}
	else
	{
		while (ps_lstfirst(stacks->b)->content != ps_get_min(stacks->b))
			stacks = ps_rra(stacks);
	}
	return (stacks);
}

int	ps_get_index(t_dlist *s, int num)
{
	int		i;
	t_dlist	*tmp;

	i = 0;
	tmp = s;
	while (tmp)
	{
		if (tmp->content == num)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
