/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:27:05 by saeby             #+#    #+#             */
/*   Updated: 2022/12/22 19:10:27 by saeby            ###   ########.fr       */
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

t_lists	*ps_lstpushb(t_lists *stack)
{
	t_dlist	*tmp;

	if (!stack->b)
		stack->b = ps_lstnew(stack->a->content);
	else
		ps_lstadd_front(&stack->b, ps_lstnew(stack->a->content));
	tmp = stack->a->next;
	free(stack->a);
	stack->a = tmp;
	return (stack);
}

t_lists	*ps_lstpusha(t_lists *stack)
{
	t_dlist	*tmp;

	if (!stack->a)
		stack->a = ps_lstnew(stack->b->content);
	else
		ps_lstadd_front(&stack->a, ps_lstnew(stack->b->content));
	tmp = stack->b->next;
	free(stack->b);
	stack->b = tmp;
	return (stack);
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
