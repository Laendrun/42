/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:35:44 by saeby             #+#    #+#             */
/*   Updated: 2022/12/05 17:50:49 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
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
*/
void	draw_background(t_vars *vars, t_point start, t_point end)
{
	size_t	i;

	i = start.x;
	while (start.y <= end.y)
	{
		while (i <= end.x)
		{
			mlx_put_pixel(vars->img, i, start.y, vars->bg_color);
			//printf("i(x): %zu, start.y: %zu, img addr: %p\n", i, start.y, &vars->img);
			//put_mlx_pixel(vars, i, start.y, vars->bg_color);
			i++;
		}
		i = start.x;
		start.y++;
	}
}
/*
void	draw_player(t_vars *vars)
{
	t_point	player_end;

	player_end.x = vars->player.position.x + SIZE;
	player_end.y = vars->player.position.y + SIZE;

	//printf("player x: %zu, player y: %zu\n", vars->player.position.x, vars->player.position.y);
	draw_rect(vars, vars->player.position, player_end, vars->player.color);
}
*/