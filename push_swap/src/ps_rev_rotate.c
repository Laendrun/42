/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:35:11 by saeby             #+#    #+#             */
/*   Updated: 2022/12/23 22:36:15 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*ps_rra(t_lists *stacks)
{
	write(1, "rra\n", 4);
	stacks->count++;
	stacks->a = ps_lstrrotate(stacks->a);
	return (stacks);
}

t_lists	*ps_rrb(t_lists *stacks)
{
	write(1, "rrb\n", 4);
	stacks->count++;
	stacks->b = ps_lstrrotate(stacks->b);
	return (stacks);
}

t_lists	*ps_rrr(t_lists *stacks)
{
	write(1, "rrr\n", 4);
	stacks->count += 2;
	stacks->a = ps_lstrrotate(stacks->a);
	stacks->b = ps_lstrrotate(stacks->b);
	return (stacks);
}
