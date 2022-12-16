/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:44:30 by saeby             #+#    #+#             */
/*   Updated: 2022/10/24 14:41:24 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i_str;
	unsigned int	j;

	i_str = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i_str] != '\0')
	{
		while (haystack[i_str + j] == needle[j] && haystack[i_str + j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i_str);
		}
		i_str++;
		j = 0;
	}
	return (0);
}
