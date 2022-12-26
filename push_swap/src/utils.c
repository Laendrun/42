/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:25:05 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 17:55:09 by saeby            ###   ########.fr       */
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
	long	max;

	tmp = a;
	max = a->content;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
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
