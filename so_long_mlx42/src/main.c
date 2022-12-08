/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:54 by saeby             #+#    #+#             */
/*   Updated: 2022/12/05 18:38:36 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_vars		vars;
	t_player	player;


	//player.texture->mlx_texture = mlx_load_png("./img/player.png");
	player.texture->xpm_texture = mlx_load_xpm42("img/player.xpm42");
	
	vars.player.position.x = 0;
	vars.player.position.y = 0;
	vars.player.color = 0xFF0000FF;
	vars.bg_color = 0x000000FF;
	vars.map.width = 10;
	vars.map.height = 10;
	vars.mlx = mlx_init(vars.map.width * SIZE, vars.map.height * SIZE, WIN_NAME, false);
	vars.img = mlx_new_image(vars.mlx, vars.map.width * SIZE, vars.map.height * SIZE);

	mlx_image_to_window(vars.mlx, vars.img, 0, 0);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_key_hook(vars.mlx, key_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	return (EXIT_SUCCESS);
}