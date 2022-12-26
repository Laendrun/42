/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:35:14 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 12:56:13 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// size - 1 because we don't want to check the next of 
// the last element (=>segfault)

int	is_sorted(t_lists *stacks)
{
	int		size;
	int		i;
	t_dlist	*tmp;

	tmp = stacks->a;
	size = ps_lstsize(tmp);
	i = 0;
	while (i < size - 1)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}
