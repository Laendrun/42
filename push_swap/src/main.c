/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:18:54 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 13:01:03 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ecrire l'operation meme si rien n'est fait ?
// genre si je fais pa mais que y a rien dans b, est-ce que je dois quand même 
// print que j'ai fait pa ou pas ?

int	main(int ac, char *av[])
{
	t_lists	*stacks;
	int		i;

	i = 1;
	stacks = malloc(2 * sizeof(t_dlist));
	if (ac == 1)
		ps_error(stacks);
	stacks->b = NULL;
	stacks->a = NULL;
	stacks->count = 0;
	stacks = parse_args(stacks, ac, av);
	stacks = sort(stacks);
	return (0);
}

t_lists	*sort(t_lists *stacks)
{
	int	i;

	i = ps_lstsize(stacks->a);
	ft_printf("-------start-----\n");
	ps_lstprint(stacks->a);
	ft_printf("-----------------\n");
	if (i <= 5)
		stacks = ps_small_sort(stacks);
	ft_printf("-----------------\n");
	ft_printf("op. count: %u\n", stacks->count);
	ft_printf("-----------------\n\n");
	ft_printf("-------end-------\n");
	ps_lstprint(stacks->a);
	ft_printf("-----------------\n");
	return (stacks);
}

t_lists	*parse_args(t_lists *stacks, int ac, char *av[])
{
	int		i;
	long	tmp;

	i = 1;
	while (i < ac)
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
