/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:06:46 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 13:04:14 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*ps_sort_three(t_lists *stacks)
{
	t_dlist	*lt;
	t_dlist	*ft;

	while (!is_sorted(stacks))
	{
		lt = ps_lstlast(stacks->a);
		ft = ps_lstfirst(stacks->a);
		if (ft->content < lt->content && ft->next->content > lt->content)
		{
			stacks = ps_sa(stacks);
			stacks = ps_ra(stacks);
		}
		else if (ft->content > ft->next->content && ft->content < lt->content)
			stacks = ps_sa(stacks);
		else if (ft->content > lt->content && ft->content < ft->next->content)
			stacks = ps_rra(stacks);
		else if (ft->content > ft->next->content && ft->content > lt->content)
			stacks = ps_ra(stacks);
		else
		{
			stacks = ps_ra(stacks);
			stacks = ps_sa(stacks);
		}
	}
	return (stacks);
}

t_lists	*ps_sort_four(t_lists *stacks)
{
	stacks = ps_push_smallest_up_a(stacks);
	stacks = ps_pb(stacks);
	stacks = ps_sort_three(stacks);
	stacks = ps_pa(stacks);
	return (stacks);
}

t_lists	*ps_sort_five(t_lists *stacks)
{
	stacks = ps_push_smallest_up_a(stacks);
	stacks = ps_pb(stacks);
	stacks = ps_sort_four(stacks);
	stacks = ps_pa(stacks);
	return (stacks);
}

t_lists	*ps_small_sort(t_lists *stacks)
{
	if (ps_lstsize(stacks->a) == 2)
	{
		if (stacks->a->content > stacks->a->next->content)
			stacks = ps_sa(stacks);
	}
	if (ps_lstsize(stacks->a) == 3)
		stacks = ps_sort_three(stacks);
	if (ps_lstsize(stacks->a) == 4)
		stacks = ps_sort_four(stacks);
	if (ps_lstsize(stacks->a) == 5)
		ps_sort_five(stacks);
	return (stacks);
}
