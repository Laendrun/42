/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:05:02 by saeby             #+#    #+#             */
/*   Updated: 2022/09/27 21:43:05 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *))
{
	t_list			*tmp;
	t_ilst			*new;
	unsigned int	i;

	tmp = lst;
	new = ft_lstnew(f(tmp->content));
	tmp = tmp->next;
	while (tmp)
	{
		new = ft_lstnew(f(tmp->content));
		new = new->next;
		tmp = tmp->next;
	}
	return (new);
}
