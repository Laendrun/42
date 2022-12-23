/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:34:50 by saeby             #+#    #+#             */
/*   Updated: 2022/12/23 20:43:13 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*ps_pa(t_lists *stacks)
{
	write(1, "pa\n", 3);
	return (ps_lstpusha(stacks));
}

t_lists	*ps_pb(t_lists *stacks)
{
	write(1, "pb\n", 3);
	return (ps_lstpushb(stacks));
}