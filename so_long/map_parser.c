/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:09:14 by saeby             #+#    #+#             */
/*   Updated: 2022/12/09 14:30:41 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			map->g_w = ft_strlen(line);
		line = get_next_line(fd);
	}
	close(fd);
	return(1);
}

int		fill_grid(t_map *map)
{
	int			fd;
	size_t		x;
	size_t		y;
	char		*line;
	char		**grid;

	grid = malloc(map->g_h * sizeof(char *));
	fd = open(map->path, O_RDONLY);
	x = 0;
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		grid[y] = malloc((map->g_w - 1) * sizeof(char));
		while (x < map->g_w - 1)
		{
			grid[y][x] = line[x];
			x++;
		}
		x = 0;
		y++;
		line = get_next_line(fd);
	}
	map->grid = grid;
	close(fd);
	return (1);
}