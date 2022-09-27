/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:10:22 by saeby             #+#    #+#             */
/*   Updated: 2022/09/27 13:33:42 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;

	tmp = (unsigned char *) dst;
	tmp2 = (unsigned char *) src;
	while (n > 0)
	{
		*(tmp++) = *(tmp2++);
		n--;
	}
	return (dst);
}
