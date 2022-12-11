/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:35:50 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 21:16:24 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac == 2)
	{
		vars.map.path = av[1];
		parse_map(&vars);
	}

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, WIN_NAME);
	vars.img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
									&vars.line_length, &vars.endian);
	mlx_hook(vars.win, 2, 1L << 0, key_handler, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_window, &vars);
	mlx_loop(vars.mlx);	
}