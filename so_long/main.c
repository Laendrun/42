/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:18:15 by saeby             #+#    #+#             */
/*   Updated: 2022/12/09 22:20:50 by saeby            ###   ########.fr       */
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
	t_g_list	*tmp;
	t_vars		vars;
	
	vars.map.path = av[1];
	if(parse_map(&vars.map))
	{
		fill_grid(&vars.map);
		tmp = vars.map.grid_list->next;
		while (tmp)
		{
			if (tmp->type == '1')
				printf("x: %2zu, y: %2zu, WALL\n", tmp->g_pos.px_x, tmp->g_pos.px_y);
			else if (tmp->type == 'E')
				printf("x: %2zu, y: %2zu, EXIT\n", tmp->g_pos.px_x, tmp->g_pos.px_y);
			else if (tmp->type == 'C')
				printf("x: %2zu, y: %2zu, COLLECTIBLE\n", tmp->g_pos.px_x, tmp->g_pos.px_y);
			else if (tmp->type == 'P')
				vars.player.pos = tmp->g_pos;
			else
				printf("x: %2zu, y: %2zu,           \n", tmp->g_pos.px_x, tmp->g_pos.px_y);
			tmp = tmp->next;
		}

		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, vars.map.g_w * SIZE, vars.map.g_h * SIZE, WIN_NAME);

		vars.player.sprite.img = mlx_xpm_file_to_image(vars.mlx, "img/p_sp.xpm", &vars.player.sprite.px_w, &vars.player.sprite.px_h);
		printf("player start_pos:\n");
		printf("x: %2zu, y: %2zu\n", vars.player.pos.px_x, vars.player.pos.px_y);
		/*
		vars.w_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/w_sp.xpm", &vars.w_sp.px_w, &vars.w_sp.px_h);
		vars.s_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/s_sp.xpm", &vars.s_sp.px_w, &vars.s_sp.px_h);
		vars.c_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/c_sp.xpm", &vars.c_sp.px_w, &vars.c_sp.px_h);
		vars.e_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/e_sp.xpm", &vars.e_sp.px_w, &vars.e_sp.px_h);
		*/
		vars.f_sp.img = mlx_xpm_file_to_image(vars.mlx, "img/f_sp.xpm", &vars.f_sp.px_w, &vars.f_sp.px_h);
		// Close window when pressing esc or the red crosd
		mlx_hook(vars.win, 2, 0L, keyHandler, &vars);
		mlx_hook(vars.win, 17, 0L, close_window, &vars);
		vars.bg_color = 0xFFFFFF;

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
	(void) vars;
	//draw_background(vars);
	//draw_player(vars);
	
	return (0);
}