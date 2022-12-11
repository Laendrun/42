/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:31:54 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 17:04:52 by saeby            ###   ########.fr       */
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
			mlx_put_image_to_window(vars->mlx, vars->win, vars->f_sp.img, \
			s.px_x, s.px_y);
			s.px_x += SIZE;
		}
		s.px_x = 0;
		s.px_y += SIZE;
	}
}

void	draw_player(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->p_sp.img, \
			vars->player.pos.px_x * SIZE, vars->player.pos.px_y * SIZE);
}

void	draw_map(t_vars *vars)
{
	t_point	s;

	s.px_x = 0;
	s.px_y = 0;
	while (s.px_y < vars->map.g_h * SIZE)
	{
		while (s.px_x < vars->map.g_w * SIZE)
		{
			if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == WALL)
				put_sp(vars, s, WALL);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == COLLECT)
				put_sp(vars, s, COLLECT);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == START)
				put_sp(vars, s, START);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == EXIT)
				put_sp(vars, s, EXIT);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == FLOOR)
				put_sp(vars, s, FLOOR);
			s.px_x += SIZE;
		}
		s.px_x = 0;
		s.px_y += SIZE;
	}
}

void	put_sp(t_vars *vars, t_point s, char t)
{
	if (t == WALL)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->w_sp.img, \
														s.px_x, s.px_y);
	else if (t == COLLECT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->c_sp.img, \
														s.px_x, s.px_y);
	else if (t == START)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->s_sp.img, \
														s.px_x, s.px_y);
	else if (t == EXIT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->e_sp.img, \
														s.px_x, s.px_y);
	else if (t == FLOOR)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->f_sp.img, \
														s.px_x, s.px_y);
}

void	draw_moves(t_vars *vars)
{
	int	h;
	int	t;
	int	u;

	h = (vars->moves / 100);
	t = (vars->moves / 10) % 10;
	u = ((vars->moves % 100) % 10);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[h].img, \
														0 * SIZE + 10, 10);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[t].img, \
														1 * SIZE + 10, 10);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[u].img, \
														2 * SIZE + 10, 10);
}
