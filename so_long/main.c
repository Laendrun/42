/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:18:15 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 13:22:19 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		ft_printf("No map specified !\n");
		exit(0);
	}
	else if (ac == 2 && check_map_name(av[1]))
	{
		ft_printf("Wrong map name !\n");
		exit(0);
	}
	t_vars		vars;
	
	vars.map.path = av[1];
	vars.collected = 0;
	vars.exitUnlocked = 0;
	vars.map.exitAccessible = 0;
	vars.map.accessibleCollectibles = 0;
	vars.collectibles = 0;
	vars.won = 0;
	vars.moves = 0;
	parse_map(&vars.map);
	fill_grid(&vars);
	free_tiles(&vars);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.g_w * SIZE, vars.map.g_h * SIZE, WIN_NAME);
	vars.img = mlx_new_image(vars.mlx, vars.map.g_w * SIZE, vars.map.g_h * SIZE);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
									&vars.line_length, &vars.endian);

	vars.p_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/p_sp.xpm", &vars.p_sp.px_w, &vars.p_sp.px_h);
	vars.w_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/w_sp.xpm", &vars.w_sp.px_w, &vars.w_sp.px_h);
	vars.s_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/s_sp.xpm", &vars.s_sp.px_w, &vars.s_sp.px_h);
	vars.c_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/c_sp_3.xpm", &vars.c_sp.px_w, &vars.c_sp.px_h);
	vars.e_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/e_sp.xpm", &vars.e_sp.px_w, &vars.e_sp.px_h);
	vars.f_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/f_sp.xpm", &vars.f_sp.px_w, &vars.f_sp.px_h);
	vars.d_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/d_sp.xpm", &vars.d_sp.px_w, &vars.d_sp.px_h);
	vars.yw_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/yw_sp.xpm", &vars.yw_sp.px_w, &vars.yw_sp.px_h);
	vars.digits_sp = malloc(10 * sizeof(t_sprite));
	vars.digits_sp[0].img = mlx_xpm_file_to_image(vars.mlx, "img/0_sp.xpm", &vars.digits_sp[0].px_w, &vars.digits_sp[0].px_h);
	vars.digits_sp[1].img = mlx_xpm_file_to_image(vars.mlx, "img/1_sp.xpm", &vars.digits_sp[1].px_w, &vars.digits_sp[1].px_h);
	vars.digits_sp[2].img = mlx_xpm_file_to_image(vars.mlx, "img/2_sp.xpm", &vars.digits_sp[2].px_w, &vars.digits_sp[2].px_h);
	vars.digits_sp[3].img = mlx_xpm_file_to_image(vars.mlx, "img/3_sp.xpm", &vars.digits_sp[3].px_w, &vars.digits_sp[3].px_h);
	vars.digits_sp[4].img = mlx_xpm_file_to_image(vars.mlx, "img/4_sp.xpm", &vars.digits_sp[4].px_w, &vars.digits_sp[4].px_h);
	vars.digits_sp[5].img = mlx_xpm_file_to_image(vars.mlx, "img/5_sp.xpm", &vars.digits_sp[5].px_w, &vars.digits_sp[5].px_h);
	vars.digits_sp[6].img = mlx_xpm_file_to_image(vars.mlx, "img/6_sp.xpm", &vars.digits_sp[6].px_w, &vars.digits_sp[6].px_h);
	vars.digits_sp[7].img = mlx_xpm_file_to_image(vars.mlx, "img/7_sp.xpm", &vars.digits_sp[7].px_w, &vars.digits_sp[7].px_h);
	vars.digits_sp[8].img = mlx_xpm_file_to_image(vars.mlx, "img/8_sp.xpm", &vars.digits_sp[8].px_w, &vars.digits_sp[8].px_h);
	vars.digits_sp[9].img = mlx_xpm_file_to_image(vars.mlx, "img/9_sp.xpm", &vars.digits_sp[9].px_w, &vars.digits_sp[9].px_h);

	// Close window when pressing esc or the red crosd
	mlx_hook(vars.win, 2, 1L<<0, keyHandler, &vars);
	mlx_hook(vars.win, 17, 1L<<0, close_window, &vars);

	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
}


int	render(t_vars *vars)
{
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
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
		mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[(vars->moves / 100)].img, 1 * SIZE + 10, 3 * SIZE + 10);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[(vars->moves / 10) % 10].img, 2 * SIZE + 10, 3 * SIZE + 10);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->digits_sp[(vars->moves % 100) % 10].img, 3 * SIZE + 10, 3 * SIZE + 10);
	}
	
	return (0);
}