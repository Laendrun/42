/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:09:14 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 12:14:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *s)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	exit(1);
}

int	parse_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error("Map not found.");
	map->g_h = 0;
	map->g_w = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->g_h++;
		if (map->g_h == 1)
			map->g_w = ft_linelen(line);
		if (ft_linelen(line) != map->g_w)
			map_error("Map not rectangular.");
		line = get_next_line(fd);
	}
	close(fd);
	return(1);
}

int		fill_grid(t_vars *vars)
{
	int			fd;
	t_point		g_pos;
	char		*line;

	vars->map.grid = malloc(vars->map.g_h * sizeof(char *));
	vars->map.tiles = malloc(vars->map.g_h * sizeof(t_tile *));
	g_pos.px_x = 0;
	g_pos.px_y = 0;
	fd = open(vars->map.path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		vars->map.grid[g_pos.px_y] = malloc((vars->map.g_w - 1) * sizeof(char));
		vars->map.tiles[g_pos.px_y] = malloc((vars->map.g_w - 1) * sizeof(t_tile));
		while (g_pos.px_x < vars->map.g_w)
		{
			vars->map.grid[g_pos.px_y][g_pos.px_x] = line[g_pos.px_x];
			vars->map.tiles[g_pos.px_y][g_pos.px_x].t = line[g_pos.px_x];
			vars->map.tiles[g_pos.px_y][g_pos.px_x].v = 0;
			if (unknown_character(vars->map.tiles[g_pos.px_y][g_pos.px_x].t))
				map_error("Unrecognized character in map file.");
			else if (vars->map.grid[g_pos.px_y][g_pos.px_x] == START && !vars->startFound)
			{
				vars->startFound = 1;
				vars->player.pos = g_pos;
				vars->player.start_pos = g_pos;
			}
			else if (vars->map.grid[g_pos.px_y][g_pos.px_x] == START && vars->startFound)
				map_error("Multiple start positions.");
			else if (vars->map.grid[g_pos.px_y][g_pos.px_x] == EXIT && !vars->exitFound)
				vars->exitFound = 1;
			else if (vars->map.grid[g_pos.px_y][g_pos.px_x] == EXIT && vars->exitFound)
				map_error("Multiple exits.");
			else if (vars->map.grid[g_pos.px_y][g_pos.px_x] == COLLECTIBLE)
				vars->collectibles++;
			g_pos.px_x++;
		}
		g_pos.px_x = 0;
		g_pos.px_y++;
		line = get_next_line(fd);
	}
	if (vars->collectibles <= 0)
		map_error("No collectibles found on the map.");
	if (walls_error(vars))
		map_error("Map not enclosed in walls.");
	check_path(vars->player.pos, vars);
	if (!vars->map.exitAccessible)
		map_error("No valid path to exit.");
	if (vars->map.accessibleCollectibles != vars->collectibles)
		map_error("No path to all collectibles.");
	close(fd);
	return (1);
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
	if (c != COLLECTIBLE && c != START && c != EXIT && c != WALL && c != FLOOR && c != 'D')
		return (1);
	return (0);
}