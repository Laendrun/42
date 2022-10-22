/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:28:16 by saeby             #+#    #+#             */
/*   Updated: 2022/09/27 18:48:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
