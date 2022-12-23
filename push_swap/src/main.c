/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:18:54 by saeby             #+#    #+#             */
/*   Updated: 2022/12/23 21:49:48 by saeby            ###   ########.fr       */
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
	long	tmp;

	i = 1;
	stacks = malloc(2 * sizeof(t_dlist));
	if (ac == 1)
		ps_error(stacks);
	stacks->b = NULL;
	stacks->a = NULL;
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

	i = ps_lstsize(stacks->a);

	if (i == 3)
		ps_sort_three(stacks);

	//ft_printf("stack A size: %d\n", i);

	ps_lstprint(stacks->a);

	return (0);
}