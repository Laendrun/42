/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:18:17 by saeby             #+#    #+#             */
/*   Updated: 2022/12/16 07:10:42 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_map_info(t_env *env)
{
	int		fd;
	char	*line;
	char	**f_line;

	fd = open(env->map.path, O_RDONLY);
	if (fd < 0)
		map_error("Map not found.");
	env->map.h = 0;
	env->map.w = 0;
	line = get_next_line(fd);
	f_line = ft_split(line, ' ');
	while (f_line[env->map.w])
		env->map.w++;
	while (line)
	{
		env->map.h++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	parse_map(t_env *env)
{
	int		fd;
	char	*line;
	char	**f_line;
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	fd = open(env->map.path, O_RDONLY);
	if (fd < 0)
		map_error("Map not found.");
	env->map.i_grid = malloc(env->map.h * sizeof(int *));
	if (!env->map.i_grid)
		map_error("Error allocating memory.");
	while(y < env->map.h)
	{
		env->map.i_grid[y] = malloc(env->map.w * sizeof(int));
		if (!env->map.i_grid[y])
			map_error("Error allocating memory.");
		line = get_next_line(fd);
		f_line = ft_split(line, ' ');
		while (++x < env->map.w)
			env->map.i_grid[y][x] = ft_atoi(f_line[x]);
		x = 0;
		y++;
	}
}

void	fill_points_vector(t_env *env)
{
	size_t	x;
	size_t	y;
	size_t	i;

	env->points = malloc(env->map.h * env->map.w * sizeof(t_vector3));
	if (!env->points)
		map_error("Error allocating memory.");
	x = 0;
	y = 0;
	i = 0;
	while (y < env->map.h)
	{
		while (x < env->map.w)
		{
			env->points[i++] = (t_vector3){x, y, env->map.i_grid[y][x]};
			x++;
		}
		x = 0;
		y++;
	}
}