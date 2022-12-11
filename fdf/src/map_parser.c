/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:12:42 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 21:56:12 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_error(char *s)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	exit(1);
}

void	parse_map(t_vars *vars)
{
	int		fd;
	char	*line;
	size_t	i;
	size_t	j;

	ft_printf("map> %s\n", vars->map.path);
	fd = open(vars->map.path, O_RDONLY);
	if (fd < 0)
		map_error("Map not found.");
	i = 0;
	j = 0;
	vars->map.g_h = 0;
	vars->map.g_w = 0;
	line = get_next_line(fd);
	while (line)
	{
		vars->map.g_h++;
		line = get_next_line(fd);
	}
	close(fd);
	fd = open(vars->map.path, O_RDONLY);
	vars->map.c_grid = malloc(vars->map.g_h * sizeof(char *));
	//vars->map.i_grid = malloc(vars->map.g_h * sizeof(int *));
	while (i < vars->map.g_h)
	{
		line = get_next_line(fd);
		vars->map.c_grid[i] = ft_split(line, ' ');
		i++;
	}
	i = 0;
	while (i < vars->map.g_h)
	{
		while (vars->map.c_grid[i][j])
		{
			ft_printf("i:%d, j:%d, >%s\n", i, j, vars->map.c_grid[i][j]);
			//vars->map.i_grid[i][j] = ft_atoi(vars->map.c_grid[i][j]);
			j++;
		}
		j = 0;
		i++;
	}

	close(fd);
}