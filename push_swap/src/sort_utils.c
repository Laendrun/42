/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:14:18 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 11:38:16 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_biggest_up(t_lists *stacks, char c);


// Take a new look at that, it doesn't work really how it should...
void	ps_push_smallest_up(t_lists *stacks, char c)
{
	int		sm_ind;
	t_dlist	*s;

	if (c == 'a')
		s = stacks->a;
	else
		s = stacks->b;
	sm_ind = ps_get_index(s, ps_get_min(s));
	if (sm_ind < ps_lstsize(s) / 2)
	{
		while (ps_lstfirst(s)->content != ps_get_min(s))
		{
			if (c == 'a')
				s = stacks->a;
			else
				s = stacks->b;
			stacks = ps_ra(stacks);
		}
	}
}

int	ps_get_index(t_dlist *s, int num)
{
	int	i;
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