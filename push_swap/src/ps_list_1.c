/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:27:05 by saeby             #+#    #+#             */
/*   Updated: 2022/12/23 21:22:51 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ps_lstfirst(t_dlist *lst)
{
	t_dlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while(tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

t_dlist	*ps_lstswap(t_dlist *first)
{
	t_dlist	*tmp;
	t_dlist	*second;

	tmp = first;
	second = first->next;
	first = second;
	tmp->next = second->next;
	first->next = tmp;
	first->prev = NULL;
	return (first);
}

t_lists	*ps_lstpushb(t_lists *stacks)
{
	t_dlist	*tmp;

	if (!stacks->a)
		return (stacks);
	if (!stacks->b)
		stacks->b = ps_lstnew(stacks->a->content);
	else
		ps_lstadd_front(&stacks->b, ps_lstnew(stacks->a->content));
	tmp = stacks->a->next;
	free(stacks->a);
	stacks->a = tmp;
	return (stacks);
}

t_lists	*ps_lstpusha(t_lists *stacks)
{
	t_dlist	*tmp;

	if (!stacks->b)
		return (stacks);
	if (!stacks->a)
		stacks->a = ps_lstnew(stacks->b->content);
	else
		ps_lstadd_front(&stacks->a, ps_lstnew(stacks->b->content));
	tmp = stacks->b->next;
	free(stacks->b);
	stacks->b = tmp;
	return (stacks);
}

t_dlist	*ps_lstrotate(t_dlist *lst)
{
	t_dlist	*second;
	t_dlist	*last;

	if (!lst)
		return (NULL);
	last = ps_lstlast(lst);
	second = lst->next;
	second->prev = NULL;
	lst->prev = last;
	lst->next = NULL;
	last->next = lst;
	lst = second;
	return (lst);
}

t_dlist	*ps_lstrrotate(t_dlist *lst)
{
	t_dlist	*last;
	t_dlist	*second_to_last;

	if (!lst)
		return (NULL);
	last = ps_lstlast(lst);
	second_to_last = last->prev;
	lst->prev = last;
	last->next = lst;
	last->prev = NULL;
	second_to_last->next = NULL;
	lst = last;
	return (lst);
}
