/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:50:57 by saeby             #+#    #+#             */
/*   Updated: 2023/01/02 16:56:30 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 04:24:41 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/16 04:24:42 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int		*tab;
	int		i;

	if (start > end)
		tab = (int *)malloc(sizeof(int) * (start - end) + 1);
	else
		tab = (int *)malloc(sizeof(int) * (end - start) + 1);
	i = 0;
	while (start != end)
	{
		tab[i++] = end;
		end -= (start > end) ? -1 : 1;
	}
	tab[i] = end;
	return (tab);
}
/*
int main(void)
{
	int	start;
	int	end;
	int	i;
	int	*tab;

	start = -5;
	end = 5;
	tab = ft_rrange(start, end);
	i = 0;
	while (i < (end - start) + 1)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
*/