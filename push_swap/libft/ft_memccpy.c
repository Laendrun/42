/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:16:29 by saeby             #+#    #+#             */
/*   Updated: 2022/09/28 10:01:35 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;

	tmp = (unsigned char *) dst;
	tmp2 = (unsigned char *) src;
	while (n > 0)
	{
		if (*(tmp2) == c)
		{
			*(tmp++) = *(tmp2++);
			*(tmp) += 1;
			return (tmp);
		}
		*(tmp++) = *(tmp2++);
		n--;
	}
	return (NULL);
}
