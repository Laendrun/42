/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:54:58 by saeby             #+#    #+#             */
/*   Updated: 2022/09/26 22:56:50 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// code wrote usingh this source : https://www.geeksforgeeks.org/write-memcpy/
// check the discussion board, it has the code implemented in the linux kernel
// for memmove
// at the very bottom of the page there's also an explanation for the below
// code

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp;
	const unsigned char	*s;

	tmp = dst;
	s = src;
	if (dst <= src)
	{
		while (len--)
			*tmp++ = *s++;
	}
	else
	{
		s += len;
		tmp += len;
		while (len--)
			*--tmp = *--s;
	}
	return (dst);
}
