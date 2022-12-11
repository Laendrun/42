/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:10:09 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 20:10:37 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tiles(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->map.g_h)
	{
		free(vars->map.tiles[i]);
		vars->map.tiles[i] = NULL;
		i++;
	}
	free(vars->map.tiles);
	vars->map.tiles = NULL;
}
