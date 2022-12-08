/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:18:15 by saeby             #+#    #+#             */
/*   Updated: 2022/12/05 12:15:37 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	(void) argv;
	(void) argc;
	/*
	if (argc != 2)
	{
		ft_printf("No map specified !");
		exit(0);
	}*/
	t_vars	vars;
	//t_sprite	player_sprite;
	//int	width;
	//int	height;

	vars.map.path = "maps/map.ber";
	parse_map(&vars.map);
	ft_printf("h: %u, w: %u\n", vars.map.height, vars.map.width);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.width*SIZE+1, vars.map.height*SIZE+1, WIN_NAME);
	vars.img = mlx_new_image(vars.mlx, vars.map.width*SIZE+1, vars.map.height*SIZE+1);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
									&vars.line_length,&vars.endian);
	
	vars.player.position.x = 0;
	vars.player.position.y = 0;
	vars.player.color = 0xFF0000;

	//player_sprite.src = mlx_xpm_file_to_image(vars.mlx, "img/test.xpm", &width, &height);
	//printf("sprite address: %p\n", player_sprite.src);

	// Close window when pressing esc or the red crosd
	mlx_hook(vars.win, 2, 0L, keyHandler, &vars);
	mlx_hook(vars.win, 17, 0L, close_window, &vars);
	vars.bg_color = 0x0;

	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}


int	render(t_vars *vars)
{
	t_point	bg_start;
	t_point	bg_end;
	
	bg_start.x = 0;
	bg_start.y = 0;
	bg_end.x = vars->map.width*SIZE+1;
	bg_end.y = vars->map.height*SIZE+1;
	draw_background(vars, bg_start, bg_end);
	draw_player(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}