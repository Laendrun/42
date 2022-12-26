/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:20:59 by saeby             #+#    #+#             */
/*   Updated: 2022/12/26 13:03:35 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ps_lstnew(int content)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ps_lstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	last = ps_lstlast(*lst);
	if (!last)
		*lst = new;
	last->next = new;
	new->prev = last;
}

void	ps_lstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*curr;

	curr = *lst;
	curr->prev = new;
	new->next = *lst;
	*lst = new;
}

int	ps_lstsize(t_dlist *lst)
{
	t_dlist	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_dlist	*ps_lstlast(t_dlist *lst)
{
	t_dlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
