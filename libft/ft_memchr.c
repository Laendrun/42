/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:50:54 by saeby             #+#    #+#             */
/*   Updated: 2022/09/26 22:51:30 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// https://opensource.apple.com/source/xnu/xnu-2782.30.5/bsd/libkern/memchr.c

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
