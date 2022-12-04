/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:31:54 by saeby             #+#    #+#             */
/*   Updated: 2022/12/04 22:12:39 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_rect(t_vars *vars, t_point start, t_point end, int color)
{
	size_t	i;

	i = start.x;
	while (start.y <= end.y)
	{
		while (i <= end.x)
		{
			put_mlx_pixel(vars, i, start.y, color);
			i++;
		}
		i = start.x;
		start.y++;
	}
}

void	draw_background(t_vars *vars, t_point start, t_point end)
{
	size_t	i;

	i = start.x;
	while (start.y <= end.y)
	{
		while (i <= end.x)
		{
			put_mlx_pixel(vars, i, start.y, vars->bg_color);
			i++;
		}
		i = start.x;
		start.y++;
	}
}

void	draw_player(t_vars *vars)
{
	t_point	player_end;

	player_end.x = vars->player.position.x + vars->player.size;
	player_end.y = vars->player.position.y + vars->player.size;

	//printf("player x: %zu, player y: %zu\n", vars->player.position.x, vars->player.position.y);
	draw_rect(vars, vars->player.position, player_end, vars->player.color);
}

void	put_mlx_pixel(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
