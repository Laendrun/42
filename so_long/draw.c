/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:31:54 by saeby             #+#    #+#             */
/*   Updated: 2022/12/09 15:25:17 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
void	draw_rect(t_vars *vars, t_point start, t_point end, int color)
{
	size_t	i;

	i = start.px_x;
	while (start.px_y <= end.px_y)
	{
		while (i <= end.px_x)
		{
			put_mlx_pixel(vars, i, start.px_y, color);
			i++;
		}
		i = start.px_x;
		start.px_y++;
	}
}
*/
/*
void	draw_background(t_vars *vars, t_point start, t_point end)
{
	size_t	i;

	i = start.px_x;
	while (start.px_y <= end.px_y)
	{
		while (i <= end.px_x)
		{
			put_mlx_pixel(vars, i, start.px_y, vars->bg_color);
			i++;
		}
		i = start.px_x;
		start.px_y++;
	}
}
*/
void	draw_background(t_vars *vars)
{
	t_point	s;
	t_point	e;

	s.px_x = 0;
	s.px_y = 0;
	e.px_x = vars->map.g_w * SIZE;
	e.px_y = vars->map.g_h * SIZE;
	while (s.px_y < e.px_y)
	{
		while (s.px_x < e.px_x)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->f_sp.img, s.px_x, s.px_y);
			s.px_x += SIZE;
		}
		s.px_x = 0;
		s.px_y += SIZE;
	}
}

void	draw_player(t_vars *vars)
{
	(void) vars;
	
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player.sprite.img, vars->player.pos.px_x, vars->player.pos.px_y);
	/*
	mlx_put_image_to_window(vars->mlx, vars->win, vars->w_sp.img, vars->player.pos.px_x+50, vars->player.pos.px_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->s_sp.img, vars->player.pos.px_x+100, vars->player.pos.px_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->c_sp.img, vars->player.pos.px_x, vars->player.pos.px_y+50);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->e_sp.img, vars->player.pos.px_x+50, vars->player.pos.px_y+50);
	*/
}
/*
void	put_mlx_pixel(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/