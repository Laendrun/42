/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:32:15 by saeby             #+#    #+#             */
/*   Updated: 2022/09/26 22:34:07 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	char			*res;

	res = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strcat(res, s1);
	ft_strcat(res, s2);
	return (res);
}
