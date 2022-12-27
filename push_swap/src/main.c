/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:18:54 by saeby             #+#    #+#             */
/*   Updated: 2022/12/27 16:33:16 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_lists		*stacks;

	stacks = malloc(2 * sizeof(t_dlist));
	if (ac == 1)
		ps_error(stacks);
	stacks->b = NULL;
	stacks->a = NULL;
	stacks->count = 0;
	if (ac == 2)
		av = ft_split((const char *) av[1], ' ');
	stacks = parse_args(stacks, ac, av);
	stacks = ps_normalize(stacks);
	stacks = sort(stacks);
	return (0);
}

t_lists	*sort(t_lists *stacks)
{
	int	i;

	i = ps_lstsize(stacks->a);
	if (i <= 5)
		stacks = ps_small_sort(stacks);
	else
		stacks = ps_med_sort(stacks);
	return (stacks);
}

t_lists	*parse_args(t_lists *stacks, int ac, char *av[])
{
	int		i;
	long	tmp;

	i = 1;
	if (ac == 2)
		i = 0;
	while (av[i])
	{
		if (!ps_str_is_posneg(av[i]))
			ps_error(stacks);
		tmp = ft_atol(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			ps_error(stacks);
		if (ps_duplicate(stacks->a, tmp))
			ps_error(stacks);
		if (!stacks->a)
			stacks->a = ps_lstnew(tmp);
		else
			ps_lstadd_back(&stacks->a, ps_lstnew(ft_atoi(av[i])));
		i++;
	}
	return (stacks);
}
