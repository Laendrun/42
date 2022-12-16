/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:17 by saeby             #+#    #+#             */
/*   Updated: 2022/12/16 17:54:38 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_env	env;
	env.scale = 35;
	if (ac == 3)
		env.scale = ft_atoi(av[2]);
	else if (ac > 3 || ac == 1)
	{
		ft_printf("No map specified.\n");
		exit(1);
	}
	env.map.path = av[1];
	parse_map_info(&env);
	parse_map(&env);
	fill_points_vector(&env);
	free_i_grid(&env);
	env.angleX = 2;
	env.angleY = 2;
	//env.alpha = 0.610865238;
	//env.beta = 0.785398;
	env.angleZ = 2;
	fill_rotation_matrices(&env);
	rotate_points(&env);
	fill_projection_matrix(&env);
	project_points(&env);
	scale_points(&env, env.scale);
	translate_points(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, WIN_NAME);
	env.img = mlx_new_image(env.mlx, WIN_W, WIN_H);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, \
									&env.line_length, &env.endian);
	mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	mlx_hook(env.win, 17, 1L << 0, close_window, &env);

	mlx_loop_hook(env.mlx, render, &env);
	mlx_loop(env.mlx);
	return (0);
}

int	render(t_env *env)
{
	//printf("angle: %f\n", env->angle);
	//fill_rotation_matrices(env);
	//rotate_points(env);
	//env->angle += 0.01;
	//draw_background(env);
	//project_points(env);
	//scale_points(env, 10);
	//translate_points(env);
	size_t	x;
	size_t	y;
	size_t	i;
	size_t	j;

	x = 0;
	y = 0;
	while (y < env->map.h)
	{
		while (x < env->map.w)
		{
			i = x + y * env->map.w;
			if (x != env->map.w - 1 && y != env->map.h - 1)
			{
				j = (x + 1) + y * env->map.w;
				ft_draw_line(env, env->final_points[i], env->final_points[j], 0xFFFFFFFF);
				j = x + (y + 1) * env->map.w;
				ft_draw_line(env, env->final_points[i], env->final_points[j], 0xFFFFFFFF);
			}
			if (x == env->map.w - 1 && y != env->map.h - 1)
			{
				j = x + (y + 1) * env->map.w;
				ft_draw_line(env, env->final_points[i], env->final_points[j], 0xFFFFFFFF);
			}
			if (x != env->map.w - 1 && y == env->map.h - 1)
			{
				j = (x + 1) + y * env->map.w;
				ft_draw_line(env, env->final_points[i], env->final_points[j], 0xFFFFFFFF);
			}
			// if x != env->map.w - 1 && y != env->map.h - 1
				// draw line from (x; y) to (x + 1; y)
				// draw line from (x; y) to (x; y + 1)
			// if x == env->map.w - 1 && y != env->map.h - 1
				// draw line from (x; y) to (x; y + 1)
			// if x != env->map.w && y == env->map.h - 1
				// draw line from (x; y) to (x + 1; y)
			// if x == env->map.w - 1 && y == env->map.h - 1
				// do nothing -> last spot bottom right
			x++;
		}
		x = 0;
		y++;
	}
	//ft_draw_line(env, (t_vector2){0, WIN_H}, (t_vector2){WIN_W, 0}, 0xFFFF0000);
	//ft_draw_line(env, (t_vector2){0, 0}, (t_vector2){WIN_W, WIN_H}, 0xFF00FF00);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}