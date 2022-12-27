/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:45:48 by saeby             #+#    #+#             */
/*   Updated: 2022/12/27 21:52:02 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	tmp = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
