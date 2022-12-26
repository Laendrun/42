/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:02:58 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 19:59:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*ps_med_sort(t_lists *stacks)
{
	t_dlist	*ft;
	t_dlist	*sc;

	stacks = ps_presort(stacks);
	while (!is_sorted(stacks))
	{
		ft = ps_lstfirst(stacks->a);
		sc = ft->next;
		if (ft > sc)
		{
			stacks = ps_sa(stacks);
			stacks = ps_ra(stacks);
		}
	}
	return (stacks);
}

t_lists	*ps_presort(t_lists *stacks)
{
	while (ps_lstsize(stacks->a) > 3)
		stacks = ps_pb(stacks);
	stacks = ps_sort_three(stacks);
	while (ps_lstsize(stacks->b) > 0)
	{
		stacks = ps_pa(stacks);
		if (stacks->a->content > stacks->a->next->content)
			stacks = ps_sa(stacks);
		else if (stacks->a->content > ps_lstlast(stacks->a)->content)
			stacks = ps_ra(stacks);
	}
	return (stacks);
}
