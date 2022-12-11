/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:19:03 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 18:19:24 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_grid(t_vars *vars, char c, t_point p)
{
	if (c == START)
	{
		vars->start_found++;
		vars->player.pos = p;
		vars->player.start_pos = p;
	}
	else if (vars->map.grid[p.px_y][p.px_x] == EXIT)
		vars->exit_found++;
	else if (vars->map.grid[p.px_y][p.px_x] == COLLECT)
		vars->collectibles++;
}

void	check_map(t_vars *vars)
{
	if (vars->collectibles <= 0)
		map_error("No collectibles found on the map.");
	if (walls_error(vars))
		map_error("Map not enclosed in walls.");
	if (!vars->map.exit_accessible)
		map_error("No valid path to exit.");
	if (vars->map.accessible_collectibles != vars->collectibles)
		map_error("No path to all collectibles.");
	if (vars->start_found == 0 || vars->start_found > 1)
		map_error("Multiple start positions.");
	if (vars->exit_found == 0 || vars->exit_found > 1)
		map_error("Multiple exit found.");
}

int	walls_error(t_vars *vars)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	while (x < vars->map.g_w)
	{
		if (vars->map.grid[y][x] != WALL)
			return (1);
		else if (vars->map.grid[vars->map.g_h - 1][x] != WALL)
			return (1);
		x++;
	}
	x = 0;
	while (y < vars->map.g_h)
	{
		if (vars->map.grid[y][x] != WALL)
			return (1);
		else if (vars->map.grid[y][vars->map.g_w - 1] != WALL)
			return (1);
		y++;
	}
	return (0);
}

int	unknown_character(int c)
{
	if (c != COLLECT && c != START && c != EXIT && c != WALL \
									&& c != FLOOR)
		return (1);
	return (0);
}
