/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:08:40 by saeby             #+#    #+#             */
/*   Updated: 2022/09/27 13:35:08 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	size_t			src_len;
	size_t			dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && j < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (! (dstsize == 0 || dst_len > dstsize))
		dst[i + j] = 0;
	return (dst_len + src_len);
}
