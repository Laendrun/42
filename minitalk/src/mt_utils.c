/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:12:30 by saeby             #+#    #+#             */
/*   Updated: 2022/12/31 18:25:56 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*mt_strjoin(char *s, char c)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *) malloc((ft_strlen(s) + 2 * sizeof(char)));
	if (!res)
		return (NULL);
	while (s[i++])
		res[i] = s[i];
	res[i++] = c;
	res[i] = 0;
	return (res);
}