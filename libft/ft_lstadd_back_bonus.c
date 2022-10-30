/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:38:43 by saeby             #+#    #+#             */
/*   Updated: 2022/10/29 17:57:01 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_back_bonus.c
 * @author saeby (saeby@42lausane.ch)
 * @version 1.0
 * @date 2022-10-29
 */
#include "libft.h"

/**
 * @fn void ft_lstadd_back(t_list **alst, t_list *new)
 * Adds a new element at the end of the chained list **alst.
 * @param alst Adress of the first element of the list (&list)
 * @param new Pointer to the element to be added to the list (element)
 */
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*alst);
	if (!last)
		*alst = new;
	else
		last->next = new;
}
