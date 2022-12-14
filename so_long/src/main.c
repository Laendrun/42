/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:18:15 by saeby             #+#    #+#             */
/*   Updated: 2022/12/14 11:38:29 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_vars		vars;

	if (ac == 1)
		map_error("No map specified.");
	else if (ac > 2)
		map_error("Too many arguments.");
	else if (ac == 2 && check_map_name(av[1]))
		map_error("Wrong map name.");
	init_game(&vars, av[1]);
	parse_map(&vars.map);
	fill_grid(&vars);
	free_tiles(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.g_w * SIZE, \
								vars.map.g_h * SIZE, WIN_NAME);
	vars.img = mlx_new_image(vars.mlx, vars.map.g_w * SIZE, \
								vars.map.g_h * SIZE);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
									&vars.line_length, &vars.endian);
	load_sprites(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_handler, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_window, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
}

int	render(t_vars *vars)
{
	draw_background(vars);
	if (!vars->won)
	{
		draw_map(vars);
		draw_player(vars);
		draw_moves(vars);
	}
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->yw_sp.img, 0, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[\
								(vars->moves / 100)].img, 1 * SIZE + 10, \
															3 * SIZE + 10);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[\
								(vars->moves / 10) % 10].img, 2 * SIZE + 10, \
															3 * SIZE + 10);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[\
								(vars->moves % 100) % 10].img, 3 * SIZE + 10, \
															3 * SIZE + 10);
	}
	return (0);
}
