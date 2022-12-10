/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:09:14 by saeby             #+#    #+#             */
/*   Updated: 2022/12/10 18:12:00 by saeby            ###   ########.fr       */
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
	map->g_h = 0;
	map->g_w = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->g_h++;
		if (map->g_h == 1)
			map->g_w = ft_strlen(line) - 1;
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
	g_pos.px_x = 0;
	g_pos.px_y = 0;
	fd = open(vars->map.path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		vars->map.grid[g_pos.px_y] = malloc((vars->map.g_w - 1) * sizeof(char));
		while (g_pos.px_x < vars->map.g_w)
		{
			vars->map.grid[g_pos.px_y][g_pos.px_x] = line[g_pos.px_x];
			if (unknown_character(vars->map.grid[g_pos.px_y][g_pos.px_x]))
				map_error("Unrecognized character in map file.");
			if (vars->map.grid[g_pos.px_y][g_pos.px_x] == 'P' && !vars->startFound)
			{
				vars->startFound = 1;
				vars->player.pos = g_pos;
			}
			else if (vars->map.grid[g_pos.px_y][g_pos.px_x] == 'P' && vars->startFound)
				map_error("Multiple start positions.");

			if (vars->map.grid[g_pos.px_y][g_pos.px_x] == 'E' && !vars->exitFound)
				vars->exitFound = 1;
			else if (vars->map.grid[g_pos.px_y][g_pos.px_x] == 'E' && vars->exitFound)
				map_error("Multiple exits.");

			if (vars->map.grid[g_pos.px_y][g_pos.px_x] == 'C')
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
		if (vars->map.grid[y][x] != '1')
			return (1);
		else if (vars->map.grid[vars->map.g_h - 1][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (y < vars->map.g_h)
	{
		if (vars->map.grid[y][x] != '1')
			return (1);
		else if (vars->map.grid[y][vars->map.g_w - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	unknown_character(int c)
{
	if (c != 'C' && c != 'P' && c != 'E' && c != '1' && c != '0')
		return (1);
	return (0);
}