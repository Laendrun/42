/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:40:52 by saeby             #+#    #+#             */
/*   Updated: 2022/10/26 21:41:01 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list			*tmp;
	unsigned int	i;

	if (!lst)
		return (NULL);
	tmp = lst;
	i = 0;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}