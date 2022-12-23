/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:35:14 by saeby             #+#    #+#             */
/*   Updated: 2022/12/23 21:49:26 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_lists *stacks)
{
	int		size;
	int		i;
	t_dlist	*tmp;

	if (ps_lstsize(stacks->b) != 0)
		return (0);
	tmp = stacks->a;
	size = ps_lstsize(tmp);
	i = 0;
	while (i < size - 1) // size - 1 because we don't want to check the next of the last element (=>segfault)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}