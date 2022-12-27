/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:02:58 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 21:10:12 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*ps_med_sort(t_lists *stacks)
{
	t_dlist	*ft;
	t_dlist	*lt;

	stacks = ps_presort(stacks);
	while (!is_sorted(stacks) && !(ps_lstsize(stacks->b) > 0))
	{
		stacks = ps_push_biggest_up_b(stacks);
		stacks = ps_pa(stacks);
		ft = ps_lstfirst(stacks->a);
		lt = ps_lstlast(stacks->a);
		if (ft->content > lt->content)
			stacks = ps_ra(stacks);
		else if (ft->content > ft->next->content)
			stacks = ps_sa(stacks);
	}
	return (stacks);
}

t_lists	*ps_presort(t_lists *stacks)
{
	while (ps_lstsize(stacks->a) > 3)
		stacks = ps_pb(stacks);
	stacks = ps_sort_three(stacks);
	return (stacks);
}
