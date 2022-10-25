/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:05:02 by saeby             #+#    #+#             */
/*   Updated: 2022/10/25 14:17:05 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*tmp_obj;
	t_list			*new_list;
	unsigned int	i;

	new_list = NULL;
	while (lst)
	{
		tmp_obj = ft_lstnew(f(lst->content));
		if (!tmp_obj)
			return (NULL);
		ft_lstadd_back(&new_list, tmp_obj);
		lst = lst->next;
	}
	return (new_list);
}
