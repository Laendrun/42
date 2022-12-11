/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:25 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 20:39:19 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_print_s(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!s)
	{
		tmp = "(null)";
		while (tmp[i])
		{
			if (ft_print_c(tmp[i]) == -1)
				return (-1);
			i++;
		}
	}
	else
	{
		while (s[i])
		{
			if (ft_print_c(s[i]) == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}