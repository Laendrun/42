/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:25:05 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 21:08:18 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(t_lists *stacks)
{
	free(stacks);
	write(2, "Error\n", 6);
	exit(1);
}

int	ps_duplicate(t_dlist *a, int num)
{
	t_dlist	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->content == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

long	ps_get_max(t_dlist *a)
{
	t_dlist	*tmp;
	long	max_val;

	tmp = a;
	max_val = a->content;
	while (tmp)
	{
		if (tmp->content > max_val)
			max_val = tmp->content;
		tmp = tmp->next;
	}
	return (max_val);
}

long	ps_get_min(t_dlist *a)
{
	t_dlist	*tmp;
	long	min;

	tmp = a;
	min = a->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	ps_str_is_posneg(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
