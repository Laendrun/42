/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:52:30 by saeby             #+#    #+#             */
/*   Updated: 2022/12/28 12:58:30 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*ps_big_sort(t_lists *stacks)
{
	int	iterations;
	int	size;
	int	i;

	i = 0;
	size = ps_lstsize(stacks->a);
	while (!is_sorted(stacks))
	{
		iterations = 0;
		while (iterations < size && !is_sorted(stacks))
		{
			iterations++;
			if (((ps_lstfirst(stacks->a)->content >> i) & 1) == 0)
				stacks = ps_pb(stacks);
			else
				stacks = ps_ra(stacks);
		}
		while (ps_lstsize(stacks->b) > 0)
			stacks = ps_pa(stacks);
		i++;
	}
	return (stacks);
}

// same implementation as thfavre
// ( https://github.com/diabolo257/42Lausanne/blob/main/42Cursus/push_swap )
// made a simple little tweak to take less moves (more visible on big numbers)
// if you try with 10k numbers, mine will take 20k moves less than Thomas
/*
t_lists	*ps_med_sort(t_lists *stacks)
{
	int	i;
	int	iterations;
	int	size;

	i = 0;
	size = ps_lstsize(stacks->a);
	while (!is_sorted(stacks))
	{
		iterations = 0;
		while (iterations < size)
		{
			iterations++;
			if (!((ps_lstfirst(stacks->a)->content >> i) & 1))
				stacks = ps_pb(stacks);
			else
				stacks = ps_ra(stacks);
		}
		while (ps_lstsize(stacks->b) > 0)
			stacks = ps_pa(stacks);
		i++;
	}
	return (stacks);
}*/
/*
// some tests that obviously didn't work
t_lists	*ps_med_sort(t_lists *stacks)
{
	int	iterations;
	int	size;
	int	i;
	int	max;

	// place = 1;
	i = 1;
	max = ps_get_max(stacks->a);
	size = ps_lstsize(stacks->a);
	while (!is_sorted(stacks))
	{
		iterations = 0;
		while (iterations < size)
		{
			iterations++;
			printf("i: %d\n", i);
			if (((ps_lstfirst(stacks->a)->content / i) % 10) == 0)
				stacks = ps_pb(stacks);
			else
				stacks = ps_ra(stacks);
		}
		while (ps_lstsize(stacks->b) > 0)
			stacks = ps_pa(stacks);
		if (max / i == 0)
			i = 1;
		else
			i *= 10;
	}
	return (stacks);
}
*/