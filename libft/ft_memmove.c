/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:54:58 by saeby             #+#    #+#             */
/*   Updated: 2022/10/25 10:34:27 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*uc_src;
	char	*uc_dst;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	uc_src = (char *) src;
	uc_dst = (char *) dst;
	i = 0;
	if (uc_dst > uc_src)
		while (len-- > 0)
			uc_dst[len] = uc_src[len];
	else
	{
		while (i < len)
		{
			uc_dst[i] = uc_src[i];
			i++;
		}
	}
	return (dst);
}
