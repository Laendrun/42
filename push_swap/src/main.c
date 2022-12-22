/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:18:54 by saeby             #+#    #+#             */
/*   Updated: 2022/12/22 19:48:53 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_lists	*stacks;
	int		i;
	long	tmp;

	i = 1;
	stacks = malloc(2 * sizeof(t_dlist));
	stacks->b = NULL;
	stacks->a = NULL;
	while (i < ac)
	{
		if (!ft_strisdigit(av[i]))
			ps_error();
		tmp = ft_atol(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			ps_error();
		if (ps_duplicate(stacks->a, tmp))
			ps_error();
		if (!stacks->a)
			stacks->a = ps_lstnew(tmp);
		else
			ps_lstadd_back(&stacks->a, ps_lstnew(ft_atoi(av[i])));
		i++;
	}

	ft_printf("stack A size: %d\n", ps_lstsize(stacks->a));

	//ps_lstprint(stacks->a);

	return (0);
}