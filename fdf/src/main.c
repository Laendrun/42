/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:17 by saeby             #+#    #+#             */
/*   Updated: 2022/12/17 16:38:51 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_env	env;

	env.scale = 35;
	env.alpha = 0.5;
	if (ac == 3)
		env.scale = ft_atoi(av[2]);
	else if (ac > 3 || ac == 1)
	{
		ft_printf("No map specified.\n");
		exit(1);
	}
	env.map.path = av[1];
	init_map(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, WIN_NAME);
	env.img = mlx_new_image(env.mlx, WIN_W, WIN_H);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, \
									&env.line_length, &env.endian);
	mlx_hook(env.win, 4, 0, mouse_handler, &env);
	mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	mlx_hook(env.win, 17, 1L << 0, close_window, &env);
	mlx_loop_hook(env.mlx, render, &env);
	mlx_loop(env.mlx);
	return (0);
}

int	render(t_env *env)
{
	size_t	x;
	size_t	y;
	size_t	i;

	draw_background(env);
	rotate_points(env);
	scale_points(env, env->scale);
	translate_points(env);
	limits(env);
	x = 0;
	y = 0;
	while (y < env->map.h)
	{
		while (x < env->map.w)
		{
			i = x + y * env->map.w;
			connect_points(env, (t_vector3){x, y, i});
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
