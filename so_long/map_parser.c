/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:09:14 by saeby             #+#    #+#             */
/*   Updated: 2022/12/10 02:48:56 by saeby            ###   ########.fr       */
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
	t_point		g_pos;
	char		*line;

	g_pos.px_x = 0;
	g_pos.px_y = 0;
	map->grid_list = ft_lstnew('o', g_pos);
	fd = open(map->path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		//grid[g_pos.px_y] = malloc((map->g_w - 1) * sizeof(char));
		while (g_pos.px_x < map->g_w - 1)
		{
			//grid[g_pos.px_y][g_pos.px_x] = line[g_pos.px_x];
			ft_lstadd_back(&map->grid_list, ft_lstnew(line[g_pos.px_x], g_pos));
			//if (line[g_pos.px_x] == 'P')

			g_pos.px_x++;
		}
		g_pos.px_x = 0;
		g_pos.px_y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}