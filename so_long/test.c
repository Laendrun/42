/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:51:35 by saeby             #+#    #+#             */
/*   Updated: 2022/12/10 19:53:07 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;

	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
		return ;
	c = tab[begin.y][begin.x];
	if (c == 'F')
		return ;
	tab[begin.y][begin.x] = 'F';
	flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
	flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
}
