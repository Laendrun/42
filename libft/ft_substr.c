/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:27:07 by saeby             #+#    #+#             */
/*   Updated: 2022/10/25 18:06:57 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	return ((char *) malloc(1));
	if (start > ft_strlen(s) || ft_strlen(s) == 0 || len == 0)
		return (ft_calloc(1, 1));
	//res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}


int main()
{
	printf("%s\n", ft_substr("hola", 0, 1));
}