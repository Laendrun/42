/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:42:43 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 22:51:42 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_c_grid(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < vars->map.g_h)
	{
		while (j < vars->map.g_w)
		{
			ft_printf("freeing c_grid[%d][%d]\n", i, j);
			free(vars->map.c_grid[i][j]);
			j++;
		}
		j = 0;
		ft_printf("freeing c_grid[%d]\n", i);
		free(vars->map.c_grid[i]);
		i++;
	}
	ft_printf("freeing c_grid\n");
	free(vars->map.c_grid);
}