/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:02:58 by saeby             #+#    #+#             */
/*   Updated: 2022/12/27 16:34:24 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// same implementation as thfavre
// ( https://github.com/diabolo257/42Lausanne/blob/main/42Cursus/push_swap )
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
		while (iterations < size && !is_sorted(stacks))
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
}

/*
// some tests that obviously didn't work, I'll take another look at it later
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
/*
t_lists	*ps_med_sort(t_lists *stacks)
{
	int	iterations;
	int	size;
	int	place;

	place = 1;
	size = ps_lstsize(stacks->a);
	while (!is_sorted(stacks))
	{
		iterations = 0;
		while (iterations < size)
		{
			iterations++;
			if (((ps_lstfirst(stacks->a)->content / place) % place) == 0)
				stacks = ps_pb(stacks);
			else
				stacks = ps_ra(stacks);
		}
		while (ps_lstsize(stacks->b) > 0)
			stacks = ps_pa(stacks);
		place += 1;
	}
	return (stacks);
}
*/
