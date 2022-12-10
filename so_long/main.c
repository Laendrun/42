/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:18:15 by saeby             #+#    #+#             */
/*   Updated: 2022/12/10 02:55:45 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	(void) ac;
	(void) av;
	if (ac != 2)
	{
		ft_printf("No map specified !");
		exit(0);
	}
	//t_g_list	*tmp;
	t_vars		vars;
	
	vars.map.path = av[1];
	if(parse_map(&vars.map))
	{
		fill_grid(&vars.map);
		vars.player.pos.px_x = 0;
		vars.player.pos.px_y = 0;

		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, vars.map.g_w * SIZE, vars.map.g_h * SIZE, WIN_NAME);
		vars.img = mlx_new_image(vars.mlx, vars.map.g_w * SIZE, vars.map.g_h * SIZE);
		vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
										&vars.line_length, &vars.endian);

		vars.p_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/p_sp.xpm", &vars.p_sp.px_w, &vars.p_sp.px_h);
		vars.w_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/w_sp.xpm", &vars.w_sp.px_w, &vars.w_sp.px_h);
		vars.s_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/s_sp.xpm", &vars.s_sp.px_w, &vars.s_sp.px_h);
		vars.c_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/c_sp.xpm", &vars.c_sp.px_w, &vars.c_sp.px_h);
		vars.e_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/e_sp.xpm", &vars.e_sp.px_w, &vars.e_sp.px_h);
		vars.f_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/f_sp.xpm", &vars.f_sp.px_w, &vars.f_sp.px_h);
		draw_background(&vars);


		// Close window when pressing esc or the red crosd
		mlx_hook(vars.win, 2, 1L<<0, keyHandler, &vars);
		mlx_hook(vars.win, 17, 0L, close_window, &vars);

		mlx_loop_hook(vars.mlx, render, &vars);
		mlx_loop(vars.mlx);
	}
	else
	{
		ft_printf("Error parsing the map.");
		exit(1);
	}
	return (0);
}


int	render(t_vars *vars)
{
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	draw_map(vars);
	//draw_collectibles(vars);
	draw_player(vars);
	
	return (0);
}