/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:06:46 by saeby             #+#    #+#             */
/*   Updated: 2022/12/23 22:25:08 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_three(t_lists *stacks)
{
	t_dlist	*lt;
	t_dlist	*ft;

	while (!is_sorted(stacks))
	{
		lt = ps_lstlast(stacks->a);
		ft = ps_lstfirst(stacks->a);
		
		if (ft->content < lt->content && ft->next->content > lt->content)
		{
			ps_sa(stacks);
			ps_ra(stacks);
		}
		else if (ft->content > ft->next->content && ft->content < lt->content)
			ps_sa(stacks);
		else if (ft->content > lt->content && ft->content < ft->next->content)
			ps_rra(stacks);
		else if (ft->content > ft->next->content && ft->content > lt->content)
			ps_ra(stacks);
		else
		{
			ps_ra(stacks);
			ps_sa(stacks);
		}
	}
}