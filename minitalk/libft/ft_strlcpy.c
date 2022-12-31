/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:34:15 by saeby             #+#    #+#             */
/*   Updated: 2022/11/12 23:22:28 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// https://opensource.apple.com/source/xnu/xnu-4570.1.46/osfmk/arm
// /strlcpy.c.auto.html

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dstsize)
	{
		ft_memcpy(dst, src, src_len + 1);
	}
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_len);
}

// if -> dans le cas où il y a de la place pour terminer
// la string complète par NUL
// else if -> dans le cas ou il font tronquer la source 
// pour terminer la string par NUL
