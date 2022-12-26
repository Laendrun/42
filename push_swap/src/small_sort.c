/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:06:46 by saeby             #+#    #+#             */
/*   Updated: 2022/12/24 10:57:35 by saeby            ###   ########.fr       */
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
			ft_printf("if fu\n");
			ps_sa(stacks);
			ps_ra(stacks);
		}
		else if (ft->content > ft->next->content && ft->content < lt->content)
		{
			ft_printf("1st elif fu\n");
			ps_sa(stacks);
		}
		else if (ft->content > lt->content && ft->content < ft->next->content)
		{
			ft_printf("2nd elif fu\n");
			ps_rra(stacks);
		}
		else if (ft->content > ft->next->content && ft->content > lt->content)
		{
			ft_printf("3rd elif fu\n");
			ps_ra(stacks);
		}
		else
		{
			ft_printf("else fu\n");
			ps_ra(stacks);
			ps_sa(stacks);
		}
	}
	return ;
}

void	ps_sort_four(t_lists *stacks)
{
	ps_push_smallest_up(stacks, 'a');
	ps_pb(stacks);
	ps_sort_three(stacks);
	ps_pa(stacks);
}

void	ps_small_sort(t_lists *stacks)
{
	if (ps_lstsize(stacks->a) == 2)
	{
		if (stacks->a->content > stacks->a->next->content)
			ps_sa(stacks);
	}
	if (ps_lstsize(stacks->a) == 3)
		ps_sort_three(stacks);
	if (ps_lstsize(stacks->a) == 4)
		ps_sort_four(stacks);
	//if (ps_lstsize(stacks->a) == 5)
	//	ps_sort_five(stacks);
}