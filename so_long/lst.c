/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:40:52 by saeby             #+#    #+#             */
/*   Updated: 2022/12/09 21:06:49 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_g_list	*ft_lstnew(char type, t_point g_pos)
{
	t_g_list	*elem;

	elem = malloc(sizeof(t_g_list));
	if (!elem)
		return (NULL);
	//elem->content = content;
	elem->type = type;
	elem->g_pos = g_pos;
	elem->next = NULL;
	return (elem);
}

int	ft_lstsize(t_g_list *lst)
{
	t_g_list			*tmp;
	unsigned int	i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_g_list **alst, t_g_list *new)
{
	t_g_list	*last;

	last = ft_lstlast(*alst);
	if (!last)
		*alst = new;
	else
		last->next = new;
}

t_g_list	*ft_lstlast(t_g_list *lst)
{
	t_g_list			*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}