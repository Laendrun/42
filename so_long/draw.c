/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:31:54 by saeby             #+#    #+#             */
/*   Updated: 2022/12/10 22:11:15 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->p_sp.img, vars->player.pos.px_x * SIZE, vars->player.pos.px_y * SIZE);
}

void	draw_map(t_vars *vars)
{
	t_point	s;
	t_point	e;
	char	t;

	s.px_x = 0;
	s.px_y = 0;
	e.px_x = vars->map.g_w * SIZE;
	e.px_y = vars->map.g_h * SIZE;
	while (s.px_y < e.px_y)
	{
		while (s.px_x < e.px_x)
		{
			t = vars->map.grid[s.px_y / SIZE][s.px_x / SIZE];
			if (t == WALL)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->w_sp.img, s.px_x, s.px_y);
			else if (t == COLLECTIBLE)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->c_sp.img, s.px_x, s.px_y);
			else if (t == START)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->s_sp.img, s.px_x, s.px_y);
			else if (t == EXIT)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->e_sp.img, s.px_x, s.px_y);
			else if (t == FLOOR)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->f_sp.img, s.px_x, s.px_y);
			else if (t == 'D')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->d_sp.img, s.px_x, s.px_y);
			s.px_x += SIZE;
		}
		s.px_x = 0;
		s.px_y += SIZE;
	}
}

void	draw_moves(t_vars *vars)
{
	/*
	char	c;
	char	d;
	char	u;

	c = 48;
	d = 48;
	u = 48;
	*/
	mlx_put_image_to_window(vars->mlx, vars->win, vars->zero_sp.img, 2 * SIZE + 10, 10); // units
	mlx_put_image_to_window(vars->mlx, vars->win, vars->zero_sp.img, 1 * SIZE + 10, 10); // tens
	mlx_put_image_to_window(vars->mlx, vars->win, vars->zero_sp.img, 0 * SIZE + 10, 10); // hundreds
}

/*
static void put_nbr_sp(t_vars *vars, int c)
{

}
*/