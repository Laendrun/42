/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:49:55 by saeby             #+#    #+#             */
/*   Updated: 2022/10/29 08:14:40 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_calloc.c
 * @author saeby (saeby@42lausanne.ch)
 * @version 1.0
 * @date 2022-10-28
 */
#include "libft.h"

/**
 * @fn *ft_calloc(size_t count, size_t size)
 * The calloc() function contiguously allocates enough space 
 * for count objects that are size bytes of memory each and returns a pointer
 * to the allocated memory. The allocated memory is filled with bytes of
 * value zero.
 * @brief Allocate count * size bytes of value 0.
 * @param count number of elements to allocate
 * @param size size of one element 
 * @retval void* pointer to the allocated memory
 */
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	unsigned long	i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
