/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:35:01 by saeby             #+#    #+#             */
/*   Updated: 2022/12/23 20:58:22 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*ps_ra(t_lists *stacks)
{
	write(1, "ra\n", 3);
	stacks->a = ps_lstrotate(stacks->a);
	return (stacks);
}

t_lists	*ps_rb(t_lists *stacks)
{
	write(1, "rb\n", 3);
	stacks->b = ps_lstrotate(stacks->b);
	return (stacks);
}

t_lists	*ps_rr(t_lists *stacks)
{
	write(1, "rr\n", 3);
	stacks->a = ps_lstrotate(stacks->a);
	stacks->b = ps_lstrotate(stacks->b);
	return (stacks);
}