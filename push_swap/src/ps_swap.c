/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:34:15 by saeby             #+#    #+#             */
/*   Updated: 2022/12/23 20:57:47 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*ps_sa(t_lists *stacks)
{
	write(1, "sa\n", 3);
	stacks->a = ps_lstswap(stacks->a);
	return (stacks);
}

t_lists	*ps_sb(t_lists *stacks)
{
	write(1, "sb\n", 3);
	stacks->b = ps_lstswap(stacks->b);
	return (stacks);
}

t_lists	*ps_ss(t_lists *stacks)
{
	write(1, "ss\n", 3);
	stacks->a = ps_lstswap(stacks->a);
	stacks->b = ps_lstswap(stacks->b);
	return (stacks);
}
