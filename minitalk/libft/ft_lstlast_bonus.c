/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:28:16 by saeby             #+#    #+#             */
/*   Updated: 2022/12/22 13:44:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstlast_bonus.c
 * @author saeby (saeby@42lausanne.ch)
 * @version 1.0
 * @date 2022-10-29
 */
#include "libft.h"

/**
 * @fn t_list *ft_lstlast(t_list *lst)
 * Returns a pointer to the last element of the list.
 * @param lst search for the end of the list from this element
 * @return t_list* Pointer to the last element of the list
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list			*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp)
		tmp = tmp->next;
	return (tmp);
}
