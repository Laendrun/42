/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:49:55 by saeby             #+#    #+#             */
/*   Updated: 2022/09/27 09:48:33 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 16711568 => maximum allocation size possible with malloc

//#include "libft.h"
#include <stdlib.h>
//#include <limits.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	unsigned long	i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}