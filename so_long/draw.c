/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:31:54 by saeby             #+#    #+#             */
/*   Updated: 2022/12/10 03:01:16 by saeby            ###   ########.fr       */
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
	//(void) vars;
	
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->player.sprite.img, vars->player.pos.px_x, vars->player.pos.px_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->p_sp.img, vars->player.pos.px_x, vars->player.pos.px_y);
	/*
	mlx_put_image_to_window(vars->mlx, vars->win, vars->w_sp.img, vars->player.pos.px_x+50, vars->player.pos.px_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->s_sp.img, vars->player.pos.px_x+100, vars->player.pos.px_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->c_sp.img, vars->player.pos.px_x, vars->player.pos.px_y+50);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->e_sp.img, vars->player.pos.px_x+50, vars->player.pos.px_y+50);
	*/
}

void	draw_map(t_vars *vars)
{
		t_g_list	*tmp;

		tmp = vars->map.grid_list->next;
		while (tmp)
		{
			if (tmp->type == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->w_sp.img, tmp->g_pos.px_x * SIZE, tmp->g_pos.px_y * SIZE);
				//printf("x: %2zu, y: %2zu, WALL\n", tmp->g_pos.px_x, tmp->g_pos.px_y);
			else if (tmp->type == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->e_sp.img, tmp->g_pos.px_x * SIZE, tmp->g_pos.px_y * SIZE);
				//printf("x: %2zu, y: %2zu, EXIT\n", tmp->g_pos.px_x, tmp->g_pos.px_y);
			else if (tmp->type == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->c_sp.img, tmp->g_pos.px_x * SIZE, tmp->g_pos.px_y * SIZE);
				//printf("x: %2zu, y: %2zu, COLLECTIBLE\n", tmp->g_pos.px_x, tmp->g_pos.px_y);
			else if (tmp->type == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->s_sp.img, tmp->g_pos.px_x * SIZE, tmp->g_pos.px_y * SIZE);
			else if (tmp->type == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->f_sp.img, tmp->g_pos.px_x * SIZE, tmp->g_pos.px_y * SIZE);
			else if (tmp->g_pos.px_x == vars->player.pos.px_x && tmp->g_pos.px_y == vars->player.pos.px_y)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->p_sp.img, tmp->g_pos.px_x * SIZE, tmp->g_pos.px_y * SIZE);
			tmp = tmp->next;
		}
}