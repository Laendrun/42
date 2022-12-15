/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:10:22 by saeby             #+#    #+#             */
/*   Updated: 2022/10/24 16:39:14 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	tmp = (unsigned char *) dst;
	tmp2 = (unsigned char *) src;
	while (n > 0)
	{
		*(tmp++) = *(tmp2++);
		n--;
	}
	return (dst);
}
